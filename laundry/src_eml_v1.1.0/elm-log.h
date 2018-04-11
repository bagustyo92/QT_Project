#ifndef __TCT_LOG_H__
#define __TCT_LOG_H__

#include <glib.h>
#include <sqlite3.h>

#include <time.h>

#include "elm.h"


gboolean elm_buffer_open (void);
gboolean elm_buffer_close (void);
gboolean elm_entran_open (void);
gboolean elm_entran_close (void);
gboolean elm_buffer_insert_epayment_data (const ELMTscData*);
gboolean elm_buffer_insert_epayment_data2 (const ELMTscData*);
gboolean elm_insert_entran_log (const ELMTscData *tsc);

gboolean tct_log_open (void);
gboolean tct_log_close (void);
gboolean tct_log_purge (gboolean);
gboolean tct_log_insert (int, time_t);
gboolean tct_log_open_tsc (void);
gboolean tct_log_close_tsc (void);
gboolean tct_buffer_close (void);
gboolean tct_buffer_insert_newop (const ELMTscData*);///
gboolean tct_buffer_insert_sop (const ELMTscData*);///
gboolean tct_buffer_insert_tsc_open (const ELMTscData*);
gboolean tct_buffer_insert_tsc_entry (const ELMTscData*);
gboolean tct_buffer_insert_tsc_exit (const ELMTscData*);


int elm_log_close_epayment (void);
void elm_buffer_start (void);
void elm_buffer_stop (void);
gboolean elm_log_open_epayment (void);
gboolean elm_log_insert_epayment (const ELMTscData*);
gboolean elm_log_open_epayment (void);
gboolean tct_log_insert_vms (int, int);
gboolean tct_db_status (void);
gboolean tct_log_test_eop (void);
gboolean tct_log_insert_tsc (const ELMTscData*);
long tct_log_query_value (const char*, ...);
gboolean tct_log_purge_tsc (gboolean);
gboolean tct_log_purge_etoll (gboolean);
gboolean tct_buffer_insert_avc (const ELMTscData*, int);

#endif
