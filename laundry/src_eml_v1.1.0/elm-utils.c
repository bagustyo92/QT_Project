/**
 * tct-utils.c
 *
 * Tool Collecting Terminal
 * Copyright (C) 2008 - 2010 Delameta Bilano,. Ardhan Madras <ajhwb@knac.com>
 */

#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <glib.h>
#include <glib/gprintf.h>

/* time_t convertion to HH:MM:SS string format */
char* get_time (time_t *t)
{
  char *str;
  time_t tp;
  struct tm st;

  if (t)
    {
      localtime_r (t, &st);
    }
  else
    {
      tp = time (NULL);
      localtime_r (&tp, &st);
    } 
  str = g_strdup_printf ("%.2i:%.2i:%.2i", st.tm_hour, st.tm_min, st.tm_sec);
  return str;
}

/**
 * get_date:
 * @t: Time atau NULL jika waktu saat ini.
 * 
 * Returns: String yang dialokasi dengan format DD-MM-YY.
 * String tanggal format DD-MM-YY.
 **/
char* get_date (time_t *t)
{
  char *str;
  time_t tp;
  struct tm st;
  
  if (t)
    {
      localtime_r (t, &st);
    }
  else
    {
      tp = time (NULL);
      localtime_r (&tp, &st);
    }
  str = g_strdup_printf ("%.2i-%.2i-%.2i", st.tm_mday, st.tm_mon + 1,
                         (st.tm_year + 1900) % 100);
  return str;
}

/* time_t convertion to asctime() like string */
char* get_date_day (time_t *t)
{
  char *str;
  time_t tp;
  struct tm st;
  static const char const *day[7] =
  {
    "Minggu", "Senin", "Selasa", "Rabu", 
    "Kamis", "Jumat", "Sabtu"
  };
  static const char const *month[12] =
  {
    "Januari", "Februari", "Maret",     "April",   "Mei",      "Juni",  
    "Juli",    "Agustus",  "September", "Oktober", "November", "Desember"
  };

  if (t)
    localtime_r (t, &st);
  else
    {
      tp = time (NULL);
      localtime_r (&tp, &st);
    }
  str = g_strdup_printf ("%s, %.2i %s %i", day[st.tm_wday], st.tm_mday,
                         month[st.tm_mon], st.tm_year + 1900);
  return str;
}

/* time to convertion to DD/MM/YYYY string format */
char* get_dated_slash (time_t *t)
{
  char *str;
  time_t tp;
  struct tm st;

  if (t)
    {
      localtime_r (t, &st);
    }
  else
    {
      tp = time (NULL);
      localtime_r (&tp, &st);
    }
  str = g_strdup_printf ("%.2i/%.2i/%i", st.tm_mday, st.tm_mon + 1, 
                         st.tm_year + 1900);
  return str;
}

/* time_t convertion to DD-MM-YYYY string format */
char* get_dated_dash (time_t *t)
{
  char *str;
  time_t tp;
  struct tm st;

  if (t)
    {
      localtime_r (t, &st);
    }
  else
    {
      tp = time (NULL);
      localtime_r (&tp, &st);
    }
  str = g_strdup_printf ("%.2i-%.2i-%i", st.tm_mday, st.tm_mon + 1,
                         st.tm_year + 1900);
  return str;
}

/* time_t conversion to YYYY-MM-DD */
char* get_datey_dash (time_t *t)
{
  char *str;
  time_t tp;
  struct tm st;
  
  if (t)
    {
      localtime_r (t, &st);
    }
  else
    {
      tp = time (NULL);
      localtime_r (&tp, &st);
    }
  str = g_strdup_printf ("%i-%.2i-%.2i", st.tm_year + 1900, 
                         st.tm_mon + 1, st.tm_mday);
  return str;
}

/* convert unsigned integer to binary string */
char* bin2str (unsigned int val, 
               int          len)
{
  char *str = NULL;
  int i, v;
  
  if (len > 0)
    {
      str = g_malloc ((len + 1) * sizeof(char));
      memset (str, '0', len);
      for (i = (len - 1); val; val >>= 1, i--)
        {
          v = val % 2;
          *(str + i) = (v == 1) ? '1' : '0';
        }
      *(str + len) = 0;
    }
  return str;
}

/* convert binary string unsigned integer */
unsigned int str2bin (const char *bin)
{
  return strtoll (bin, NULL, 2);
}

/* send UDP data */
gboolean send_udp_data (void       *data,
                        size_t      len,
                        const char *ip,
                        int         port)
{
  struct sockaddr_in addr;
  int fd, ret;
  size_t bytes = 0;

  fd = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (fd == -1)
    return FALSE;

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr (ip);
  addr.sin_port = htons (port);

  while (bytes < len)
    {
      ret = sendto (fd, (char*) data + bytes, len - bytes, 0, 
                    (struct sockaddr *) &addr, sizeof(addr));
      if (ret <= 0)
        {
          close (fd);
          return FALSE;
        }
      bytes += ret;
    }
  close (fd);
  return TRUE;
}

ssize_t receive_udp_data (int                 s,
                          void               *data,
                          size_t              len,
                          int                 timeout,
                          struct sockaddr_in *from)
{
  g_return_val_if_fail (data != NULL, FALSE);

  int ret;
  size_t bytes = 0;
  fd_set rset;
  unsigned int addrlen = sizeof(struct sockaddr_in);
  struct timeval tv = { .tv_sec = 0, .tv_usec = timeout * 1000 };
  struct timeval tv2;
  struct sockaddr_in addr;

  while (tv.tv_usec >= G_USEC_PER_SEC)
    {
      tv.tv_sec++;
      tv.tv_usec -= G_USEC_PER_SEC;
    }
  while (bytes < len)
    {
      FD_ZERO (&rset);
      FD_SET (s, &rset);
      tv2 = tv;
      ret = select (s + 1, &rset, NULL, NULL, &tv2);
      if (ret <= 0) return ret;
      ret = recvfrom (s, (char*) data + bytes, len - bytes, 0, 
                      (struct sockaddr*) &addr, &addrlen);
      if (ret == -1) return ret;
      bytes += ret;
    }
  if (from) memcpy (from, &addr, sizeof(struct sockaddr_in));
  return bytes;
}


