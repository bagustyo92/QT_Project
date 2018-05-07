/**
 * tct-net.c - TCT network interface communication
 *
 * Toll Collecting Terminal
 * Copyright (C) 2008 - 2011, Ardhan Madras <ajhwb@knac.com> - Delameta Bilano
 *
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <mqueue.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include <glib.h>

#include "elm.h"
#include "elm-log.h"
#include "elm-utils.h"
///#include "elm-tool.h"
///#include "elm-sop.h"
#include "elm-tsc.h"
///#include "elm-alb.h"
///#include "elm-csd.h"

/* status network: TRUE up atau FALSE down */
static gboolean net_status = FALSE;

/* status thread deteksi interface network 
   TRUE jika thread sedang berjalan, FALSE jika tidak */
static gboolean net_run = FALSE;
static GStaticMutex mutex = G_STATIC_MUTEX_INIT;
static GThread *net_thread = NULL;

static GThread *echo_thread = NULL;
static GCond *echo_cond = NULL;

static char *asd_cmd = NULL;
static gboolean asd_state = FALSE;

/* kode operasi ASD */
static int asd_code;


static gboolean elm_net_get_run (void);
static void elm_net_set_run (gboolean);
static void* elm_net_thread (void*);


static gboolean elm_net_get_run (void)
{
  gboolean retval;
  
  g_static_mutex_lock (&mutex);
  retval = net_run;
  g_static_mutex_unlock (&mutex);
  return retval;
}

static void elm_net_set_run (gboolean run)
{
  g_static_mutex_lock (&mutex);
  net_run = run;
  g_static_mutex_unlock (&mutex);
}


void elm_net_start (void)
{
  if (!tct_net_get_run ())
    net_thread = g_thread_create ((GThreadFunc) tct_net_thread, NULL, TRUE, NULL);
}

void elm_net_stop (void)
{
  tct_net_set_run (FALSE);
  g_thread_join (net_thread);
}

gboolean elm_net_get_status (void)
{
  gboolean retval;
  
  g_static_mutex_lock (&mutex);
  retval = net_status;
  g_static_mutex_unlock (&mutex);
  return retval;
}

static void* elm_net_thread (void *args)
{
  int ret, s;
  unsigned int delay = G_USEC_PER_SEC >> 2;
  gboolean plugged = FALSE;
  gboolean unplugged = TRUE;
  ssize_t bytes;
  fd_set rset;
  struct elm_helper data;
  struct sockaddr_un addr = { .sun_family = AF_UNIX, .sun_path = TOOL_NAME };
  struct timeval tv = { .tv_sec = 1, .tv_usec = 0 };

  elm_debug (ELM_DEBUG_INFO, "%s: thread started\n", __func__);
  elm_net_set_run (TRUE);

start:
  while (elm_net_get_run ())
    {
      s = socket (AF_UNIX, SOCK_STREAM, 0);
      if (s == -1)
        {
          elm_debug (elm_DEBUG_ERROR, "%s: socket: %s\n", 
                     __func__, g_strerror (errno));
error:
          elm_net_set_run (FALSE);
          elm_debug (ELM_DEBUG_INFO, "%s: thread end\n", __func__);
          return NULL;
        }
      ret = connect (s, (struct sockaddr*) &addr, sizeof(addr));
      if (ret == -1)
        {
          elm_debug (elm_DEBUG_ERROR, "%s: connect: %s\n", 
                     __func__, g_strerror (errno));
          close (s);
          g_usleep (delay);
          continue;
        }

      setsockopt (s, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));

	  data.cmd = TOOL_CMD_NETSTAT;
      bytes = 0;
      while (bytes < sizeof(data))
        {
          ret = send (s, (char *) &data + bytes, sizeof(data) - bytes, 0);
          if (ret <= 0)
            {
              elm_debug (ELM_DEBUG_ERROR, "%s: send: %s\n", 
                         __func__, g_strerror (errno));
              goto error;
            }
          bytes += ret;
        }

        bytes = 0;
        while (bytes < sizeof(data))
          {
            FD_ZERO (&rset);
            FD_SET (s, &rset);
            tv = (struct timeval) { 1, 0 };

            ret = select (s + 1, &rset, NULL, NULL, &tv);
            if (ret == -1)
              {
                if (errno == EINTR) 
                  continue;
                else
                  {
                    elm_debug (ELM_DEBUG_ERROR, "%s: select: %s\n",
                               __func__, g_strerror (errno));
                    goto error;
                  }
              }
            else if (ret == 0)
              {
                elm_debug (ELM_DEBUG_WARNING, "%s: timeout\n", __func__);
                close (s);
                goto start;
              }
            
            if (!FD_ISSET (s, &rset))
              goto error;

            ret = recv (s, (char *) &data + bytes, sizeof(data) - bytes, 0);
            if (ret <= 0)
              {
                elm_debug (ELM_DEBUG_FATAL, "%s: recv: %s\n", 
                           __func__, g_strerror (errno));
                goto error;
              }
            bytes += ret;
          }

      close (s);
      g_static_mutex_lock (&mutex);
      net_status = data.value;
      g_static_mutex_unlock (&mutex);

      if (data.value && plugged)
        {
          tct_log_insert (TCT_LOG_NET_PLUGGED, 0);
          plugged = FALSE;
          unplugged = TRUE;
        }
      if (!data.value && unplugged)
        {
          tct_log_insert (TCT_LOG_NET_UNPLUGGED, 0);
          plugged = TRUE;
          unplugged = FALSE;
        }
      g_usleep (delay);
    }

  tct_net_set_run (FALSE);
  elm_debug (ELM_DEBUG_INFO, "%s: thread end\n", __func__);
  return NULL;
}


