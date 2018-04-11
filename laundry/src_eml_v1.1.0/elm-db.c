/**
 * tct-db.c - TCT PostgreSQL interface
 *
 * Tool Collecting Terminal
 * Copyright (C) 2008 - 2011 Delameta Bilano,. Ardhan Madras <ajhwb@knac.com>
 */

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <glib.h>
#include <libpq-fe.h>
#include <sqlite3.h>

#include "elm.h"
#include "elm-setting.h"
#include "elm-utils.h"
///#include "elm-tsc.h"
///#include "elm-net.h"
#include "elm-log.h"

/**
 * tct_db_connect:
 * @conn: Koneksi database.
 * 
 * Returns: TRUE jika koneksi berhasil, FALSE jika gagal.
 * Buat koneksi ke server, @conn harus ditutup walaupun
 * koneksi berhasil atau gagal.
 *
 * Fungsi ini block jika kondisi link tidak siap, sebaiknya 
 * selalu cek status link sebelum memanggil fungsi ini.
 * 
 */
gboolean elm_db_connect (PGconn **conn)
{
  char *info;
  int status;

  info = g_strdup_printf ("hostaddr=%s port=%i dbname=%s user=%s password=%s "
                          "connect_timeout=%i", pcs_setting.pcds_addr, 
                          pcs_setting.pcds_port, pcs_setting.pcds_db, 
                          pcs_setting.pcds_user, pcs_setting.pcds_passwd, 2);
  *conn = PQconnectdb (info);
  status = PQstatus (*conn);
  g_free (info);
  if (status != CONNECTION_OK)
    {
      elm_debug (ELM_DEBUG_WARNING, "%s: could not connect to "
                 "database: %s\n", __func__, PQerrorMessage (*conn));
      return FALSE;
    }
  return TRUE;
}

/**
 * tct_db_close:
 * 
 * Tutup object koneksi database.
 */
void elm_db_close (PGconn **conn)

{
  PQfinish (*conn);
}

/**
 * tct_db_test_connect:
 * 
 * Returns: TRUE jika koneksi berhasil, FALSE jika gagal.
 * Test koneksi database server.
 */
gboolean elm_db_test_connect (void)
{
  PGconn *conn;
  gboolean retval;

  retval = elm_db_connect (&conn);
  elm_db_close (&conn);
  return retval;
}


/**
 * tct_db_send_tsc_etoll:
 * @conn: Koneksi database.
 * @tsc: Data transaksi.
 *
 * Returns: TRUE jika data berhasil dikirim, FALSE jika gagal.
 *
 * Kirim data transaksi E-TOLL.
 */
gboolean elm_db_send_tsc_epayment (PGconn           *conn,
                                const ELMTscData *tsc)
{
  PGresult *result;
  char *idshift, *ttime, *tdate, *cmd;
  gboolean retval = TRUE;
  time_t tp;
  int dbstat;

  idshift = elm_get_idshift (tsc->machine, tsc->shift, tsc->period, tsc->cycle);
  tp = tsc->time_ex;
  ttime = get_time (&tp);
  tdate = get_datey_dash (&tp);

  cmd = g_strdup_printf ("SELECT enco_insert_epayment_record('%s', '%s', '%s','%i', "
                         "'%.2i', '%i', %i, '%i', %i, %li, '%s', %i, '%s')",
                         idshift, tdate, ttime,tsc->location, tsc->machine, tsc->shift, tsc->sn,
                         tsc->paket, tsc->tarif, tsc->epayment_balance, tsc->epayment_data, 
                         tsc->epayment_status, tsc->epayment_cmd);

  result = PQexec (conn, cmd);
  dbstat = PQresultStatus (result);
  elm_debug (ELM_DEBUG_INFO, "%s: %s\n", __func__, cmd);
  g_free (idshift);
  g_free (ttime);
  g_free (tdate);
  g_free (cmd);

  if (dbstat != PGRES_TUPLES_OK)
    {
      elm_debug (ELM_DEBUG_ERROR, "%s: %s\n", __func__, 
                 PQresultErrorMessage (result));
      retval = FALSE;
    }
  PQclear (result);
  return retval;
}

/**
 * tct_db_send_tsc_etoll2:
 * @conn: Koneksi database.
 * @tsc: Data transaksi.
 *
 * Returns: TRUE jika data berhasil dikirim, FALSE jika gagal.
 *
 * Kirim data transaksi E-TOLL.
 */
gboolean elm_db_send_tsc_epayment2 (PGconn           *conn,
                                const ELMTscData *tsc)
{
  PGresult *result;
  char *idshift, *ttime, *tdate, *cmd;
  gboolean retval = TRUE;
  time_t tp;
  int dbstat;
	
  idshift = elm_get_idshift (tsc->machine, tsc->shift, tsc->period, tsc->cycle);
  tp = tsc->time_ex;
  ttime = get_time (&tp);
  tdate = get_datey_dash (&tp);

  cmd = g_strdup_printf ("SELECT enco_insert_epayment_record('%s', '%s', '%s','%i', "
                         "'%.2i', '%i', %i, '%i', %i, %li, '%s', %i, '%s')",
                         idshift, tdate, ttime,tsc->location, tsc->machine, tsc->shift, tsc->sn,
                         tsc->paket, tsc->tarif, tsc->epayment_balance, tsc->epayment_data, 
                         tsc->epayment_status, tsc->epayment_cmd);

  result = PQexec (conn, cmd);
  dbstat = PQresultStatus (result);
  elm_debug (ELM_DEBUG_INFO, "%s: %s\n", __func__, cmd);
  g_free (idshift);
  g_free (ttime);
  g_free (tdate);
  g_free (cmd);

  if (dbstat != PGRES_TUPLES_OK)
    {
      elm_debug (ELM_DEBUG_ERROR, "%s: %s\n", __func__, 
                 PQresultErrorMessage (result));
      retval = FALSE;
    }
  PQclear (result);
  return retval;
}

