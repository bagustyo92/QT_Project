#ifndef __ELM_SETTING_H__
#define __ELM_SETTING_H__

typedef struct _ELMEpaymentSetting
{
  /* MANDIRI */
  char sam_pin[17];
  char instution_id[5];
  char terminal_id[9];
  char pin_area[3];
  char pin_number[17];
  /* BRI */
  char bri_mid[16];
  char bri_tid[9];
  char bri_pcd[7];
  /* BNI */
  char bni_tid[9];
  /* BCA */
  char bca_mid[13];
  char bca_tid[9];
} ELMEpaymentSetting;


typedef struct _ELMPcsSetting
{
  char pcds_addr[16];
//  char pcs_addr[16];
  char pcds_db[16];
  char pcds_user[16];
  char pcds_passwd[33];
//  char pccs_addr[16];
//  char pccs2_addr[16];     /* pccs camera dalam gardu */
//  char kspt_addr[16];
  short pcds_port;
//  short pcs_port;
//  short pccs_port;
//  short pccs2_port;        /* pccs port camera dalam gardu */   
//  short kspt_port;
} ELMPcsSetting;

typedef struct _ELMEncoSetting
{
  int elm_outlet;
  int elm_location;
  int elm_type;
  int elm_machine;
  int elm_lcd;
} ELMElmSetting;

typedef struct _ELMEncoSn
{
  int resi;
} ELMEncoSn;

typedef struct _ELMEncoCost
{
  int pkt1;
  int pkt2;
  int pkt3;
  int pkt4;
  int pkt5;
} ELMEncoCost;

/* setting ETOLL */
ELMEpaymentSetting  	epayment_setting;

/* setting PCS */
ELMPcsSetting 			pcs_setting;

/* setting ENCO */
ELMElmSetting 			elm_setting;
ELMEncoSn 				elm_sn;
ELMEncoCost 			elm_cost;

gboolean elm_setting_read_epayment(ELMEpaymentSetting*);
gboolean elm_setting_read_pcs (ELMPcsSetting*);
gboolean elm_setting_read_enco (ELMElmSetting*);
gboolean elm_setting_read_sn (ELMEncoSn*);
int setting_update_cost();
gboolean elm_setting_read_cost ();

int setting_sn_inc();


#endif
