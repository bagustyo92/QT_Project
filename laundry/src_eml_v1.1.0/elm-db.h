#ifndef __TCT_DB_H__
#define __TCT_DB_H__

#include <glib.h>
#include <libpq-fe.h>

#include "elm.h"

//extern TCTBlacklist *tct_blacklist;

void elm_db_close (PGconn**);
gboolean elm_db_connect (PGconn**);
gboolean elm_db_test_connect (void);
gboolean elm_db_send_tsc_epayment (PGconn*, const ELMTscData*);
gboolean elm_db_send_tsc_epayment2 (PGconn*, const ELMTscData*);
gboolean tct_db_new_operation (PGconn*, const ELMData*);
gboolean tct_db_start_of_procedure (PGconn*, const ELMData*);
gboolean tct_db_send_tsc_open (PGconn*, const ELMTscData*);
gboolean tct_db_send_tsc_entry (PGconn*, const ELMTscData*);
gboolean tct_db_send_tsc_exit (PGconn*, const ELMTscData*);

gboolean tct_db_end_of_period (ELMData*);
gboolean tct_db_test_eop (PGconn*, const ELMData*);
gboolean tct_db_request_eop (const ELMData*);
gboolean tct_db_login (ELMData*);
gboolean tct_db_send_log (PGconn*, const ELMLog*);
gboolean tct_db_send_garduaktif (const ELMData*);
long tct_db_get_time (void);
gboolean tct_db_send_vms (PGconn*, int, int);
gboolean tct_db_get_pul (const ELMData*, int*, char**);
//gboolean tct_db_get_blacklist (ELMBlacklist**);
gboolean tct_db_send_avc (PGconn*, const ELMTscData*);

#endif
