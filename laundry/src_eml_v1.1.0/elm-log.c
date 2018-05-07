/**
 * tct-log.c - TCT log utility (sqlite3 thread-safe backend)
 *
 * Toll Collecting Terminal
 * Copyright (C) 2008 - 2011, Delameta Bilano - Ardhan Madras <ajhwb@knac.com>
 *
 * TODO: Convert all sqlite statements to quote-safe function sqlite3_mprintf().
 **/

#include <time.h>
#include <stdlib.h>
#include <string.h>

#include <glib.h>
#include <libpq-fe.h>
#include <sqlite3.h>

#include "elm.h"
#include "elm-log.h"
#include "elm-utils.h"
#include "elm-setting.h"
#include "elm-db.h"
#include "elm-cost.h"
#include "elm_membercard.h"

// #include "elm-net.h"

#define TSC_LOG_TABLE  "tsc"
#define TCT_LOG_TABLE  "tct"
#define BUFFER_TABLE   "buffer"
#define ENTRAN_TABLE   "entran"
#define MEMBERCARD_TABLE "mc"

/* handler log TCT dan transaksi */
//static sqlite3 *tct_log = NULL;
//static sqlite3 *tsc_log = NULL;
static sqlite3 *epayment_log = NULL;

static sqlite3 *buffer_log = NULL;
static sqlite3 *entran_log = NULL;

static GThread *buffer_thread = NULL;

static gboolean buffer_run = FALSE;
static gboolean db_status = FALSE;
static gboolean eop_status = FALSE;
//static int log_qvalue;

static GStaticMutex buffer_mutex = G_STATIC_MUTEX_INIT;



//static gboolean tct_buffer_insert_tct_log (const TCTLog*);
//static int tct_log_query_value_cb (void*, int, char**, char**);


static gboolean elm_buffer_get_run (void);
static void* elm_buffer_thread (void*);

/**
 * tct_buffer_open:
 * 
 * Returns: TRUE jika berhasil, FALSE jika gagal.
 * Buka handler buffer TCT.
 **/
gboolean elm_buffer_open (void)
{
  int ret;
  ret = sqlite3_open (ELM_BUFFER_FILE, &buffer_log);
  if (ret != SQLITE_OK)
    {
      elm_debug (ELM_DEBUG_FATAL, "%s: could not open buffer\n", __func__);
      return FALSE;
    }
  return TRUE;
}


/**
 * tct_buffer_open:
 * 
 * Returns: TRUE jika berhasil, FALSE jika gagal.
 * Buka handler buffer TCT.
 **/
gboolean elm_entran_open (void)
{
  int ret;
  ret = sqlite3_open (ELM_ENTRAN_LOG_FILE, &entran_log);
  if (ret != SQLITE_OK)
    {
      elm_debug (ELM_DEBUG_FATAL, "%s: could not open entran\n", __func__);
      return FALSE;
    }
  return TRUE;
}

int elm_buffer_close (void)
{
  return sqlite3_close (buffer_log);
}

int elm_entran_close (void)
{
  return sqlite3_close (entran_log);
}

/**
 * tct_buffer_insert_etoll_data:
 * @tsc: Data transaksi TCT.
 *
 * Returns: TRUE jika berhasil, FALSE jika gagal.
 * 
 * Masukkan data transaksi E-TOLL ke buffer.
 */
gboolean elm_buffer_insert_epayment_data (const ELMTscData *tsc)
{
  char *cmd;
  int ret;

  cmd = sqlite3_mprintf ("INSERT INTO "BUFFER_TABLE" VALUES (NULL, %i, 0, "
                         "0, 0, %li, 0, %i, %i, %i, '%q', '%q', %i, 0, 0, %i, %i, "
                         "0, %i, 0, %li, 0, 0, 0, 0, 0, %li)", ELM_BUFFER_EPAYMENT, 
                         tsc->time_ex, tsc->machine, tsc->shift, tsc->period, 
                         tsc->epayment_data, tsc->epayment_cmd, tsc->paket, tsc->tarif, 
                         tsc->sn, tsc->epayment_status, tsc->epayment_balance, tsc->cycle);
                         
				
  ret = sqlite3_exec (buffer_log, cmd, NULL, NULL, NULL);
  sqlite3_free (cmd);
  if (ret != SQLITE_OK)
    {
      elm_debug (ELM_DEBUG_FATAL, "%s: %s\n", __func__,
                 sqlite3_errmsg (buffer_log));
      return FALSE;
    }
  return TRUE;
}

/**
 * tct_buffer_insert_etoll_data2:
 * @tsc: Data transaksi TCT.
 *
 * Returns: TRUE jika berhasil, FALSE jika gagal.
 * 
 * Masukkan data transaksi E-TOLL ke buffer.
 */
gboolean elm_buffer_insert_epayment_data2 (const ELMTscData *tsc)
{
  char *cmd;
  int ret;
/*
  cmd = sqlite3_mprintf ("INSERT INTO "BUFFER_TABLE" VALUES (NULL, %i, 0, "
                         "0, 0, %li, 0, %i, %i, %i, '%q', '%q', %i, 0, 0, %i, %i, "
                         "0, %i, 0, %li, 0, 0, 0, 0, 0, %li)", ELM_BUFFER_EPAYMENT2, 
                         tsc->time_ex, tsc->gardu, tsc->shift, tsc->period, 
                         tsc->epayment_data, tsc->epayment_cmd, tsc->gol, tsc->tarif, 
                         tsc->sn, tsc->epayment_status, tsc->epayment_balance, tsc->cycle);
*/
/*
cmd = sqlite3_mprintf ("INSERT INTO "BUFFER_TABLE" VALUES (NULL, %i, 0, "
                         "0, 0, %li, 0, %i, %i, %i, '%q', '%q', %i, 0, 0, %i, %i, "
                         "0, %i, 0, %li, 0, 0, 0, 0, 0, %li)", ELM_BUFFER_EPAYMENT2, 
                         tsc->time_ex, 1, 1, 1, 
                         tsc->epayment_data, tsc->epayment_cmd, 7, 1, 
                         1, tsc->epayment_status, tsc->epayment_balance, tsc->cycle);
 */ 

                            
cmd = sqlite3_mprintf ("INSERT INTO "BUFFER_TABLE" VALUES (NULL, %i, 0, "
                         "0, 0, %li, 0, %i, %i, %i, '%q', '%q', %i, 0, 0, %i, %i, "
                         "0, %i, 0, %li, 0, 0, 0, 0, 0, %li)", ELM_BUFFER_EPAYMENT, 
                         tsc->time_ex, tsc->machine,1, tsc->period, 
                         tsc->epayment_data, tsc->epayment_cmd,tsc->paket, tsc->tarif, 
                         tsc->sn, tsc->epayment_status, tsc->epayment_balance, tsc->cycle);
                         


  ret = sqlite3_exec (buffer_log, cmd, NULL, NULL, NULL);
  sqlite3_free (cmd);
  if (ret != SQLITE_OK)
    {
      elm_debug (ELM_DEBUG_FATAL, "%s: %s\n", __func__,
                 sqlite3_errmsg (buffer_log));
      return FALSE;
    }
  return TRUE;
}

gboolean elm_insert_entran_log (const ELMTscData *tsc)
{
  char *cmd;
  int ret;


cmd = sqlite3_mprintf ("INSERT INTO "ENTRAN_TABLE" VALUES (NULL, %i, %i, "
                         "%i,%i,%i,%i,%ul,%i",1,
                         tsc->longitude,tsc->latitude,
                         tsc->time_ex, 1, 
                         tsc->tarif,tsc->card_type, tsc->num_card, tsc->epayment_balance);


  ret = sqlite3_exec (entran_log, cmd, NULL, NULL, NULL);
  sqlite3_free (cmd);
  if (ret != SQLITE_OK)
    {
      elm_debug (ELM_DEBUG_FATAL, "%s: %s\n", __func__,
                 sqlite3_errmsg (entran_log));
      return FALSE;
    }
  return TRUE;
}

gboolean elm_log_insert_epayment (const ELMTscData *tsc)
{
  char *cmd, uid[17];
  int ret;

  g_snprintf (uid, sizeof(uid), tsc->epayment_data);

  cmd = sqlite3_mprintf ("INSERT INTO log VALUES(NULL, %li, %i, %i, %i, %i, %i, "
                         "%li, '%q', %i, '%q', '%q')", tsc->time_ex, tsc->location,
                         tsc->machine, tsc->sn, tsc->paket, tsc->tarif, 
                         tsc->epayment_balance, uid, tsc->epayment_status, 
                         tsc->epayment_data, tsc->epayment_cmd);

  ret = sqlite3_exec (epayment_log, cmd, NULL, NULL, NULL);
  sqlite3_free (cmd);

  if (ret != SQLITE_OK)
    {
      elm_debug (ELM_DEBUG_ERROR, "%s: %s\n", __func__, 
                 sqlite3_errmsg (epayment_log));
      return FALSE;
    }

  return TRUE;
}



gboolean elm_log_open_epayment (void)
{
  const char *cmd;
  gboolean exist, ret;

  exist = g_file_test (ELM_EPAYMENT_LOG_FILE,
                       G_FILE_TEST_IS_REGULAR | G_FILE_TEST_EXISTS);
  ret = sqlite3_open (ELM_EPAYMENT_LOG_FILE, &epayment_log);

  if (!exist && ret == SQLITE_OK)
    {
      cmd = "CREATE TABLE log('id' INTEGER PRIMARY KEY, 'time' "
            "INTEGER, 'gerbang' INTEGER, 'gardu' INTEGER, 'sn' INTEGER, "
            "'gol' INTEGER, 'cost' INTEGER, 'balance' INTEGER, 'uid' TEXT, "
            "'status' INTEGER, 'report' TEXT, 'cmd' TEXT)";

      ret = sqlite3_exec (epayment_log, cmd, NULL, NULL, NULL);

      if (ret != SQLITE_OK)
        {
          elm_debug (ELM_DEBUG_ERROR, "%s: %s\n", __func__,
                     sqlite3_errmsg (epayment_log));
          sqlite3_close (epayment_log);
          ret = FALSE;
        }
    }
  else if (exist && ret == SQLITE_OK)
    ret = TRUE;
  else
    {
      elm_debug (ELM_DEBUG_ERROR, "%s: could not open log\n", __func__);
      ret = FALSE;
    }

  return ret;
}

int elm_log_close_epayment (void)
{
  return sqlite3_close (epayment_log);
}


void elm_buffer_start (void)
{
  g_static_mutex_lock (&buffer_mutex);
  buffer_run = TRUE;
  g_static_mutex_unlock (&buffer_mutex);
  buffer_thread = g_thread_create ((GThreadFunc) elm_buffer_thread, 
                                   NULL, TRUE, NULL);
}

void elm_buffer_stop (void)
{
  g_static_mutex_lock (&buffer_mutex);
  buffer_run = FALSE;
  g_static_mutex_unlock (&buffer_mutex);
  g_thread_join (buffer_thread);
}

static gboolean elm_buffer_get_run (void)
{
  gboolean retval;
  g_static_mutex_lock (&buffer_mutex);
  retval = buffer_run;
  g_static_mutex_unlock (&buffer_mutex);
  return retval;
}



static void* elm_buffer_thread (void *data)
{
  ELMData tct;
  ELMTscData tsc;
  ELMLog log;
  long time;
  PGconn *conn;
  gboolean retval = FALSE, netstat;
  gboolean online = FALSE, offline = TRUE;
  char *cmd, **table, pcs[13];
  int buffer, ret, row, col, i, j, id;
  const int buffer_interval = ((double) 250 / 1000) * G_USEC_PER_SEC;
  struct tm *st;

  time=0;
  elm_debug (ELM_DEBUG_INFO, "%s: thread started, buffer interval is "
             "%i ms\n", __func__, 250);
   elm_get_cost_update();
///   get_card_member_data("select * from enco_get_membercard()");
			
  while (elm_buffer_get_run ())
    {
	
		if(((times(NULL)-time)*10)>30000)
		{
			system(" sudo find /var/log/ -size +400 | sudo xargs rm");
			elm_get_cost_update();
///			get_card_member_data("select * from enco_get_membercard()");
			time=times(NULL);
		}
		
			
		if(!(retval = elm_db_connect (&conn)))
		{
			sleep(10);
			continue;
		}
		/* periksa buffer jika kosong */
      cmd = g_strdup_printf ("SELECT * FROM "BUFFER_TABLE" LIMIT 1");
      ret = sqlite3_get_table (buffer_log, cmd, &table, &row, &col, NULL);
      g_free (cmd);
      if (ret != SQLITE_OK)
        {
          elm_debug (ELM_DEBUG_FATAL, "%s: %s\n", __func__, 
                     sqlite3_errmsg (buffer_log));
          elm_db_close (&conn);
          return NULL;
        }
      sqlite3_free_table (table);
      /* cek row dan proses semua data jika buffer tidak kosong */
      if (row == 0)
        {
          g_usleep (G_USEC_PER_SEC);
          elm_db_close (&conn);
          continue;
        }
        
       /* proteksi stack thread dengan limit query */
      cmd = g_strdup_printf ("SELECT * FROM "BUFFER_TABLE" LIMIT 50");
      ret = sqlite3_get_table (buffer_log, cmd, &table, &row, &col, NULL);
      g_free (cmd);
      if (ret != SQLITE_OK)
        {
          elm_debug (ELM_DEBUG_FATAL, "%s: %s\n", __func__, 
                     sqlite3_errmsg (buffer_log));
          elm_db_close (&conn);
          continue;
        }
		
		 for (i = 0, j = col; i < row; i++)
        {
          id = atoi (table[j]);
          buffer = atoi (table[j + 1]);

		 switch(buffer)
		 {
              case ELM_BUFFER_EPAYMENT:
                tsc.time_ex = atol (table[j + 5]);
      ////          tsc.location = atol (table[j+??]);
				tsc.location = 	elm_data.location;
                tsc.machine = atol (table[j + 7]);
                tsc.shift = atol (table[j + 8]);
                tsc.period = atol (table[j + 9]);
                tsc.paket = atol (table[j + 12]);
                tsc.tarif = atoi (table[j + 15]);
                tsc.sn = atoi (table[j + 16]);
                tsc.cycle = atol (table[j + 26]);
                tsc.epayment_status = atoi (table[j + 18]);
                tsc.epayment_balance = atol (table[j + 20]);
                g_snprintf (tsc.epayment_data, sizeof(tsc.epayment_data), 
                            "%s", table[j + 10]);
                g_snprintf (tsc.epayment_cmd, sizeof(tsc.epayment_cmd), 
                            "%s", table[j + 11]);
                retval = elm_db_send_tsc_epayment (conn, &tsc);
                break;

              case ELM_BUFFER_EPAYMENT2:
                tsc.time_ex = atol (table[j + 5]);
      ////          tsc.location = atol (table[j+??]);
               tsc.location = 	elm_data.location;

                tsc.machine = atol (table[j + 7]);
                tsc.shift = atol (table[j + 8]);
                tsc.period = atol (table[j + 9]);
                tsc.paket = atol (table[j + 12]);
                tsc.tarif = atoi (table[j + 15]);
                tsc.sn = atoi (table[j + 16]);
                tsc.cycle = atol (table[j + 26]);
                tsc.epayment_status = atoi (table[j + 18]);
                tsc.epayment_balance = atol (table[j + 20]);
                g_snprintf (tsc.epayment_data, sizeof(tsc.epayment_data), 
                            "%s", table[j + 10]);
                g_snprintf (tsc.epayment_cmd, sizeof(tsc.epayment_cmd), 
                            "%s", table[j + 11]);
                retval = elm_db_send_tsc_epayment2 (conn, &tsc);
                break;
                
			  default:
                elm_debug (ELM_DEBUG_WARNING, "%s: unknown buffer code %i\n",
                           __func__, buffer);
                goto next;
                
            }

            /* hapus data yang berhasil dikirim */
            if (retval)
              {
                /* kirim trigger ke PCS */
                
                cmd = g_strdup_printf ("DELETE FROM "BUFFER_TABLE" WHERE "
                                       "id = %i", id);
                ret = sqlite3_exec (buffer_log, cmd, NULL, NULL, NULL);
                g_free (cmd);
                if (ret != SQLITE_OK)
                  {
                    elm_debug (ELM_DEBUG_FATAL, "%s: %s\n", __func__, 
                               sqlite3_errmsg (buffer_log));
                    sqlite3_free_table (table);
                    elm_db_close (&conn);
                    return NULL;
                  }
              }
            else
              {
                break;
              }
          
next:
          j += col;
          g_usleep (buffer_interval);
        } /* for */
		
        elm_db_close (&conn);
    }
  elm_debug (ELM_DEBUG_INFO, "%s: thread end\n", __func__);
  return NULL;
}

