/*
 * Mandiri E-Toll reader communication module
 *
 * Copyright (C) 2010 - 2012, Delameta Bilano,. Ardhan Madras <ajhwb@knac.com>
 */

#ifndef _ENCO
#define _ENCO

#include <time.h>

/* Reader defined code */
#define MDR_SUCCESS						    0x30303030 /* Purchase success */
#define MDR_PURCHASE_TIMEOUT				0x31303034 /* Purchase timeout */
#define MDR_PURCHASE_INSUFFICIENT			0x30323638 /* Insufficient card amount */
#define MDR_PURCHASE_GP1				  	0x30323634 /* Grace period (EZPROX) */
#define MDR_PURCHASE_GP2				  	0x30323644 /* Grace period (DUALI) */
#define MDR_PURCHASE_UNCOMPLETED			0x31303132 /* Purchase uncompleted */
#define MDR_PURCHASE_CORRECTION				0x31303133 /* Correction (continue purchase) with previous card */
#define MDR_PURCHASE_MIFARE					0x31303036 /* Mifare card detected */
#define MDR_PURCHASE_INVALID				0x31303131 /* Non eToll/Mifare card detected */
#define MDR_PURCHASE_DOUBLE					0x30323534 /* Double purchase protection extends for 10 seconds */
#define MDR_PURCHASE_DATE				  	0x32303535 /* Invalid transaction date format */
#define MDR_SAM_PIN						    0x36334337 /* Invalid SAM pin */
#define MDR_SAM_ID						    0x36393834 /* Invalid SAM instution ID */
#define MDR_SAM_PINID					    0x30323546 /* Invalid SAM or instution ID */
#define MDR_SAM_LENGTH					  	0x31303035 /* Invalid SAM data length  */
#define MDR_SAM_NOT_INIT          			0x36453030 /* SAM Not Init */
//#define MDR_CARD_DIFF					    0x31303134 /* Diff card read_ktme >< purchase */

/* User defined code */
#define MDR_PURCHASE_DIFF			    	0x44494646 /* Requested purchased amount not equals to reported amount */
#define MDR_LRC_ERROR					    0x4c524345 /* LRC error */
#define MDR_IO_ERROR					    0x494f4552 /* IO error */
#define MDR_TIMEOUT 			        0x54494d4f /* IO timeout */
#define MDR_FAIL						      0xd0000000 /* Undefined */
#define MDR_ERROR						      0x45520000 /* General error */
#define MDR_RW_FAIL						    0x52574552 /* Read/Write Fail */
#define MDR_KTME_INVALID  	      0x2d2d0000 /* Data KTME Zero (char '0')*/
#define MDR_ON_PURCHASE           0x4f4e5055 /* reader sedang purchase */
#define MDR_CARD_DIFF   				  0x43443146 /* beda kartu */
#define MDR_REPLYCODE_ERROR       0x43443246 /* reply code command tidak sesuai */


/* Mifare code */
#define MDR_MIFARE_SUCCESS				0x30303030 /* Operation success */
#define MDR_MIFARE_CODEERR1				0x30303031 /* Code error #1 */
#define MDR_MIFARE_NOTAG				  0x30303032 /* No TAG error */
#define MDR_MIFARE_CRCERR			    0x30303033 /* CRC error */
#define MDR_MIFARE_EMPTY				  0x30303034 /* Empty (no IC card error) */
#define MDR_MIFARE_AUTHERR				0x30303035 /* Authentication error */
#define MDR_MIFARE_PARITYERR		  0x30303036 /* Parity error */
#define MDR_MIFARE_CODEERR2				0x30303037 /* Code error #2 */
#define MDR_MIFARE_SNERR				  0x30303038 /* Serial number error */
#define MDR_MIFARE_KEYERR				  0x30303039 /* Key error */
#define MDR_MIFARE_NOTAUTHERR			0x30303041 /* Not authentication error */
#define MDR_MIFARE_BITCOUNTERR		0x30303042 /* MI_BITCOUNTERR */
#define MDR_MIFARE_BYTECOUNTERR		0x30303043 /* MI_BYTECOUNTERR */
#define MDR_MIFARE_IDLE					  0x30303044 /* Idle */
#define MDR_MIFARE_TRANSFERERR		0x30303045 /* Transfer error */
#define MDR_MIFARE_WRITEERR				0x30303046 /* Write error */
#define MDR_MIFARE_INCRERR				0x30303130 /* Increment error */
#define MDR_MIFARE_DECRERR				0x30303131 /* Decrement error */
#define MDR_MIFARE_READERR				0x30303132 /* Read error */
#define MDR_MIFARE_OVERFLOWERR		0x30303133 /* Overflow error */
#define MDR_MIFARE_POLLERR				0x30303134 /* Polling error */
#define MDR_MIFARE_FRAMEERR				0x30303135 /* Framing error */
#define MDR_MIFARE_ACCESSERR			0x30303136 /* Access error */
#define MDR_MIFARE_UNKNOWNERR			0x30303137 /* Unknown command error */
#define MDR_MIFARE_ANTICOLERR			0x30303138 /* Anticollision error */
#define MDR_MIFARE_INITERR				0x30303139 /* Initialization error */
#define MDR_MIFARE_INTERFERR			0x30303146 /* Interface error */
#define MDR_MIFARE_ACCESSTIMEO		0x30303147 /* Access timeout */
#define MDR_MIFARE_NOBITANTICOL		0x30303148 /* No bitwise anticollision */
#define MDR_MIFARE_RCVBUFOVERFLOW	0x30303149 /* Receive buffer overflow */

/* Mifare key type */
#define MDR_MIFARE_KEY_A				  0x00
#define MDR_MIFARE_KEY_B				  0x01

#define MANDIRI_CARD              0x30
#define BRI_JAVA_CARD             0x31
#define BRI_DESFIRE_CARD          0x32
#define BNI_CARD                  0x33
#define BCA_CARD                  0x34
#define DKI_CARD				  0x35
#define FELICA_CARD				  0x36
#define MIFARE_CARD               0x39

#define MANDIRI_REPORT_SZ         94
#define BRI_REPORT_SZ             77
#define BNI_REPORT_SZ             218
#define BCA_REPORT_SZ             189

#define DB_ETOLL                  0x31
#define MIY_ETOLL                 0x32

#define VK1          "BBEA9101CE7ED34A"
#define VK2          "A142C17AB00A852E"

struct mdr_ctx;
typedef struct mdr_ctx mdr_ctx;




/*
struct mdr_etoll {
	unsigned long amount;
	unsigned long balance;
	time_t time[12];
};
*/

struct mdr_etoll {
	unsigned long tsc_amount;
	unsigned long last_balance;
	unsigned char tsc_cmd[25];
	time_t time[12];
};

struct mdr_etoll2 {
  unsigned long long card_num;
  unsigned int card_id;
  unsigned int eid;
  struct mdr_etoll e1;
};


struct mdr_ktme {
	int cabang;
	int gerbang;
	int gardu;
	int inst;
	int status;
	int type;
	int gol;
	int pul;
	int dir;
	unsigned short crc;
	char uid[17];
	time_t time;
};


#ifdef __cplusplus
extern "C" {
#endif

mdr_ctx *mdr_init();
void mdr_free(mdr_ctx *ctx);
int mdr_reset(mdr_ctx *ctx);
unsigned int mdr_get_status(mdr_ctx *ctx);
int mdr_init_sam(mdr_ctx *ctx, const char *pin, const char *ins, const char *termid);
int mdr2_init_sam(mdr_ctx *ctx, const char *pin, const char *ins, const char *termid);
//int bri_init_sam(mdr_ctx *ctx, const char *mid, const char *tid, const char *shift);
int bri_init_sam(mdr_ctx *ctx, const char *mid, const char *tid, const char *pcode, const char *shift);
int bni_init_sam(mdr_ctx *ctx, const char *tid);
int bca_init_sam(mdr_ctx *ctx, const char *mid, const char *tid);

int mdr_inq_balance(mdr_ctx *ctx, unsigned long long *balance, int timeout);
int mdr_purchase_debt(mdr_ctx *ctx, unsigned long amount, time_t tsc_time, int timeout,
						unsigned char *tsc_report, struct mdr_etoll2 *etoll);
int mdr_get_report(mdr_ctx *ctx, unsigned char *tsc_report);
int mdr_cancel_debt(mdr_ctx *ctx);
int mdr_get_cmd(mdr_ctx *ctx, const unsigned char **output, int *len);
int mdr_get_reply(mdr_ctx *ctx, const unsigned char **output, int *len);

int mdr2_purchase_debt(mdr_ctx *ctx, unsigned long amount, time_t tsc_time, int timeout,
						unsigned char *tsc_report, struct mdr_etoll2 *etoll);

int mdr2_get_report(mdr_ctx *ctx, unsigned char *tsc_report,int *e_id);
int mdr2_get_cardnumber(mdr_ctx *ctx, int flag, int timeout, unsigned long long *cardnum, char *id);
int mdr2_set_sam_slot(mdr_ctx *ctx, char ,char ,char ,char ,int );


#ifdef __cplusplus
}
#endif

#endif /* _ENCO */
