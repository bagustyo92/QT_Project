
#include <glib.h>

#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include <stdio.h> 

#include "elm.h"
#include "elm-setting.h"

/* EPAYMENT */
#define EPAYMENT_GROUP						 "EPAYMENT"
#define EPAYMENT_SAM_PIN_KEY			 "SAM_PIN"
#define EPAYMENT_INSTUTION_ID_KEY	"INSTUTION_ID"
#define EPAYMENT_TERMINAL_ID_KEY	 "TERMINAL_ID"
#define EPAYMENT_PIN_AREA_KEY			"PIN_AREA"
#define EPAYMENT_PIN_NUMBER_KEY		"PIN_NUMBER"
/* BRI */
#define BRI_MERCHANT_ID_KEY		 "BRI_MID"
#define BRI_TERMINAL_ID_KEY		 "BRI_TID"
#define BRI_PROCODE_ID_KEY			"BRI_PCD"
/* BNI */
#define BNI_TERMINAL_ID_KEY		 "BNI_TID"
/* BCA */
#define BCA_MERCHANT_ID_KEY		 "BCA_MID"
#define BCA_TERMINAL_ID_KEY		 "BCA_TID"

/* PCS */
#define PCS_GROUP				"PCS"
#define PCDS_ADDRESS_KEY "PCDS_ADDRESS"
#define PCDS_PORT_KEY		"PCDS_PORT"
#define PCDS_DB_KEY			"PCDS_DB"
#define PCDS_USER_KEY		"PCDS_USER"
#define PCDS_PASSWD_KEY	"PCDS_PASSWD"

/*ELM*/
#define ELM_GROUP				"ELM"
#define ELM_LCD					"ELM_LCD"
#define ELM_OUTLET			 "ELM_OUTLET"
#define ELM_LOCATION		 "ELM_LOKASI"
#define ELM_TYPE				 "ELM_TYPE"
#define ELM_MACHINE			"ELM_MACHINE"

FILE *fdsn;



gboolean elm_setting_read_pcs (ELMPcsSetting *pcs)
{
	
	GKeyFile *key;
	GError *error = NULL;
	char *tmp;
	gboolean test;

	key = g_key_file_new ();
	test = g_key_file_load_from_file (key, ELM_SETTING_FILE,
																		G_KEY_FILE_KEEP_COMMENTS, &error);
	if (!test)
		{
			elm_debug (ELM_DEBUG_FATAL, "%s: %s\n", __func__, error->message);
			g_error_free (error);
			g_key_file_free (key);
			return test;
		}
	pcs->pcds_port = g_key_file_get_integer (key, PCS_GROUP, PCDS_PORT_KEY, NULL);
	
	tmp = g_key_file_get_string (key, PCS_GROUP, PCDS_ADDRESS_KEY, NULL);
	g_snprintf (pcs->pcds_addr, sizeof(pcs->pcds_addr), tmp);
	g_free (tmp);
	
	tmp = g_key_file_get_string (key, PCS_GROUP, PCDS_DB_KEY, NULL);
	g_snprintf (pcs->pcds_db, sizeof(pcs->pcds_db), tmp);
	g_free (tmp);
	tmp = g_key_file_get_string (key, PCS_GROUP, PCDS_USER_KEY, NULL);
	g_snprintf (pcs->pcds_user, sizeof(pcs->pcds_user), tmp);
	g_free (tmp);

	tmp = g_key_file_get_string (key, PCS_GROUP, PCDS_PASSWD_KEY, NULL);
	g_snprintf (pcs->pcds_passwd, sizeof(pcs->pcds_passwd), tmp);
	g_free (tmp);

	g_key_file_free (key);
	return test;
}



gboolean elm_setting_read_epayment (ELMEpaymentSetting *epayment )
{
	GKeyFile *key;
	GError *error;
	gboolean test;
	char *tmp;

	key = g_key_file_new ();
	test = g_key_file_load_from_file (key, ELM_EPAYMENT_FILE,
																		G_KEY_FILE_KEEP_COMMENTS, &error);
	
	if (!test)
		{
			elm_debug (ELM_DEBUG_ERROR, "%s: %s\n", __func__, error->message);
			g_error_free (error);
			g_key_file_free (key);
			return test;
		}

	tmp = g_key_file_get_string (key, EPAYMENT_GROUP, EPAYMENT_SAM_PIN_KEY, NULL);
	if (tmp)
		g_snprintf (epayment->sam_pin, sizeof(epayment->sam_pin), "%s", tmp);
	
	g_free (tmp);

	
	tmp = g_key_file_get_string (key, EPAYMENT_GROUP, EPAYMENT_INSTUTION_ID_KEY, NULL);
	if (tmp)
		g_snprintf (epayment->instution_id, 
								sizeof(epayment->instution_id), "%s", tmp);
	g_free (tmp);

	
	tmp = g_key_file_get_string (key, EPAYMENT_GROUP, EPAYMENT_TERMINAL_ID_KEY, NULL);
	if (tmp)
		g_snprintf (epayment->terminal_id, 
								sizeof(epayment->terminal_id), "%s", tmp);
	g_free (tmp);

	
	tmp = g_key_file_get_string (key, EPAYMENT_GROUP, EPAYMENT_PIN_AREA_KEY, NULL);
	if (tmp)
		g_snprintf (epayment->pin_area, 
								sizeof(epayment->pin_area), "%s", tmp);
	g_free (tmp);

	
	tmp = g_key_file_get_string (key, EPAYMENT_GROUP, EPAYMENT_PIN_NUMBER_KEY, NULL);
	if (tmp)
		g_snprintf (epayment->pin_number, 
								sizeof(epayment->pin_number), "%s", tmp);
	g_free (tmp);

	
/* BRI */
	tmp = g_key_file_get_string (key, EPAYMENT_GROUP, BRI_MERCHANT_ID_KEY, NULL);
	if (tmp)
		g_snprintf (epayment->bri_mid, 
								sizeof(epayment->bri_mid), "%s", tmp);
	g_free (tmp);

	
	tmp = g_key_file_get_string (key, EPAYMENT_GROUP, BRI_TERMINAL_ID_KEY, NULL);
	if (tmp)
		g_snprintf (epayment->bri_tid, 
								sizeof(epayment->bri_tid), "%s", tmp);
	g_free (tmp);

	
	tmp = g_key_file_get_string (key, EPAYMENT_GROUP, BRI_PROCODE_ID_KEY, NULL);
	if (tmp)
		g_snprintf (epayment->bri_pcd, 
								sizeof(epayment->bri_pcd), "%s", tmp);
	g_free (tmp);

	
/* BNI */
	tmp = g_key_file_get_string (key, EPAYMENT_GROUP, BNI_TERMINAL_ID_KEY, NULL);
	if (tmp)
		g_snprintf (epayment->bni_tid, 
								sizeof(epayment->bni_tid), "%s", tmp);
	g_free (tmp);
	
	
	
/* BCA */
	tmp = g_key_file_get_string (key, EPAYMENT_GROUP, BCA_MERCHANT_ID_KEY, NULL);
	if (tmp)
		g_snprintf (epayment->bca_mid,
								sizeof(epayment->bca_mid), "%s", tmp);
	g_free (tmp);

	
	tmp = g_key_file_get_string (key, EPAYMENT_GROUP, BCA_TERMINAL_ID_KEY, NULL);
	if (tmp)
		g_snprintf (epayment->bca_tid, 
								sizeof(epayment->bca_tid), "%s", tmp);
	g_free (tmp);
/*		 */

	
	if (strlen (epayment->sam_pin) < 16
			|| strlen (epayment->instution_id) < 4
			|| strlen (epayment->terminal_id) < 8
			|| strlen (epayment->pin_area) < 2
			|| strlen (epayment->pin_number) < 16)
		{
			elm_debug (ELM_DEBUG_ERROR, "%s: invalid etoll setting\n", __func__);
			test = FALSE;
		}
	else
		{
			elm_debug (ELM_DEBUG_INFO, "%s: sam_pin: %s, instution_id: %s, "
								 "terminal_id: %s, pin_area: %s, pin_number: %s\n",
								 __func__, epayment->sam_pin, epayment->instution_id,
								 epayment->terminal_id, epayment->pin_area,
								 epayment->pin_number);

			elm_debug (ELM_DEBUG_INFO, "%s: bri merchant_id: %s, bri terminal_id: %s\n"
								 "bni terminal_id: %s\n"
								 "bca merchant_id: %s, bca terminal_id: %s\n",__func__,
								 epayment->bri_mid, epayment->bri_tid,
								 epayment->bni_tid,
								 epayment->bca_mid, epayment->bca_tid);
		}
		
	
	g_key_file_free (key);
	
	return test;
}


gboolean elm_setting_read_enco (ELMElmSetting* elm)
{
		GKeyFile *key;
	GError *error = NULL;
	char *tmp;
	gboolean test;

	key = g_key_file_new ();
	test = g_key_file_load_from_file (key, ELM_SETTING_FILE,
																		G_KEY_FILE_KEEP_COMMENTS, &error);
	if (!test)
		{
			elm_debug (ELM_DEBUG_FATAL, "%s: %s\n", __func__, error->message);
			g_error_free (error);
			g_key_file_free (key);
			return test;
		}
	elm->elm_outlet = g_key_file_get_integer (key, ELM_GROUP, ELM_OUTLET, NULL);
	elm->elm_location = g_key_file_get_integer (key, ELM_GROUP, ELM_LOCATION, NULL);
	elm->elm_type = g_key_file_get_integer (key, ELM_GROUP, ELM_TYPE, NULL);
	elm->elm_machine = g_key_file_get_integer (key, ELM_GROUP, ELM_MACHINE, NULL);
	elm->elm_lcd = g_key_file_get_integer (key, ELM_GROUP, ELM_LCD, NULL);
	
	g_key_file_free (key);
	return test;
}


 gboolean elm_setting_read_sn (ELMEncoSn* elm)
{
	GKeyFile *key;
	GError *error = NULL;
	char *tmp;
	gboolean test;

	key = g_key_file_new ();
	test = g_key_file_load_from_file (key, ELM_SN_FILE,
										G_KEY_FILE_KEEP_COMMENTS, &error);
	if (!test)
		{
			elm_debug (ELM_DEBUG_FATAL, "%s: %s\n", __func__, error->message);
			g_error_free (error);
			g_key_file_free (key);
			return test;
		}
	elm->resi = g_key_file_get_integer (key, "SN", "RESI", NULL);
	
	
	g_key_file_free (key);
	return test;
}

gboolean elm_setting_read_cost ()
{
	GKeyFile *key;
	GError *error = NULL;
	char *tmp;
	gboolean test;

	key = g_key_file_new ();
	test = g_key_file_load_from_file (key, ELM_COST_FILE,
										G_KEY_FILE_KEEP_COMMENTS, &error);
	if (!test)
		{
			elm_debug (ELM_DEBUG_FATAL, "%s: %s\n", __func__, error->message);
			g_error_free (error);
			g_key_file_free (key);
			return test;
		}
	elm_cost.pkt1 = g_key_file_get_integer (key, "COST", "PAKET1", NULL);
	elm_cost.pkt2 = g_key_file_get_integer (key, "COST", "PAKET2", NULL);
	elm_cost.pkt3 = g_key_file_get_integer (key, "COST", "PAKET3", NULL);
	elm_cost.pkt4 = g_key_file_get_integer (key, "COST", "PAKET4", NULL);
	elm_cost.pkt5 = g_key_file_get_integer (key, "COST", "PAKET5", NULL);
	
	
	g_key_file_free (key);
	return test;
}


int setting_sn_inc() 
{
	char buffer [100];
	
	fdsn=fopen(ELM_SN_FILE,"w+");
	elm_data.sn=elm_data.sn+1;
	sprintf(buffer,"[SN]\nRESI=%d",elm_data.sn);
	fprintf(fdsn,"%s",buffer);
	elm_debug (ELM_DEBUG_INFO, "%s: sn update\n", __func__);
	fclose(fdsn);
	

  return 0;
}

int setting_update_cost() 
{
	char buffer [200];
	
	fdsn=fopen(ELM_COST_FILE,"w+");
	elm_debug (ELM_DEBUG_INFO, "%s: cost update\n", __func__);
	sprintf(buffer,"[COST]\nPAKET1=%d\nPAKET2=%d\nPAKET3=%d\nPAKET4=%d\nPAKET5=%d",elm_cost.pkt1,elm_cost.pkt2,elm_cost.pkt3,elm_cost.pkt4,elm_cost.pkt5);
	fprintf(fdsn,"%s",buffer);
	fclose(fdsn);
	

  return 0;
}
