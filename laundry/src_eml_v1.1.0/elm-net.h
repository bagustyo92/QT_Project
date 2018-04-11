#ifndef __ELM_NET_H__
#define __ELM_NET_H__

#include <time.h>
#include <glib.h>

#include "elm.h"

struct elm_helper {
  unsigned int cmd;
  long value;
};


#define TOOL_RESPONSE_OK   0x10
#define TOOL_RESPONSE_FAIL 0x11

#define TOOL_CMD_NETSTAT   0x30
#define TOOL_CMD_SETTIME   0x31
#define TOOL_CMD_SETSCHED  0x32


GCond *net_cond;

void elm_net_start (void);
void elm_net_stop (void);

gboolean tct_net_test_queue (void);
gboolean tct_net_test_eth (void);
gboolean tct_net_get_status (void);
gboolean tct_net_parse_cmd (const char*, unsigned char*, int*, char*);
void tct_net_echo_start (void);
gboolean tct_net_get_asd (void);
void tct_net_set_asd (gboolean);
const char* tct_net_asd_cmd (void);
gboolean tct_net_set_time (time_t);
gboolean tct_net_tsc_trigger (void);
/* trigger camera dalam gardu */
gboolean tct_net_tsc2_trigger (void);
gboolean tct_net_cancel_trigger (void);/* tambahan dari risdy */
/* trigger camera dalam gardu */
gboolean tct_net_cancel2_trigger (void);
gboolean tct_net_detection_trigger (time_t, int);
/* trigger camera dalam gardu */
gboolean tct_net_detection2_trigger (time_t, int); 
gboolean tct_net_reset_trigger (time_t, int);
/* trigger camera dalam gardu */
gboolean tct_net_reset2_trigger (time_t, int);
gboolean tct_net_ltn_trigger (time_t, TCTLtnType, int);
/* trigger camera dalam gardu */
gboolean tct_net_ltn2_trigger (time_t, TCTLtnType, int);

gboolean tct_net_obsalr_trigger (time_t, int);
gboolean tct_net_obsgandengan_trigger (time_t, int);
gboolean tct_net_long_detect_trigger (time_t, int);
gboolean tct_net_datatsc_trigger (time_t, int, ELMTscData*);

gboolean tct_net_pcs_tsc_trigger (void);
void tct_net_asd_signal (int);
gboolean tct_net_setsched (void);

#endif
