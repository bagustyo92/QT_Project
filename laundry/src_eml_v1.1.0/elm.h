#ifndef __ELM_H__
#define __ELM_H__

#include <glib.h>

#include <sys/types.h>
#include <time.h>
#include <termios.h>

#define VERSI			"V1.1.0"



static const char * const elm_outlet[] =
{
/* MAYTAG */
   [0] = "ENCO_LAUNDRY",
   [1] = "MAYTAG LAUNDRY",
   [2] = "KAIN WANGI"
    
};

static const char * const elm_location[] =
{
/* MAYTAG */
   [0] = "ENCO_LAUNDRY",
   [1] = "KALIBATA",
    
};

/* hasil akses CST */
typedef enum
{
	ELM_CST_SUCCESS = 0,		/* akses mifare sukses */
	ELM_CST_ESUCCESS,			/* akses etoll sukses */
	ELM_CST_FAIL,				/* akses mifare gagal */
	ELM_CST_EFAIL,				/* akses etoll gagal */
	ELM_CST_CANCEL,				/* akses dibatalkan */
	ELM_CST_INVALID,			/* salah jenis kartu */
	ELM_CST_USED,				/* kartu telah digunakan */
	ELM_CST_DIFF,				/* kartu berbeda (cancel ELM_ENTRY) */
	ELM_CST_TIMEOUT,			/* akses timeout */
	ELM_CST_BLACKLIST,			/* kartu diblacklist */
	ELM_CST_EXPIRED,			/* kartu expired */
	ELM_CST_INSUFFICIENT, 		/* saldo etoll tidak cukup */
	ELM_CST_GP,					/* grace period etoll */
	ELM_CST_MIFARE,				/* deteksi mifare */
	ELM_CST_ON_PURCHASE,		/* proses purchase */
	ELM_CST_KSPT,				/* deteksi kartu kspt */
	ELM_CST_CKSUM_KTME_FAIL,	/*	 */
	ELM_CST_INVALID_GATE		/*	 */
} ELMCstAccess;



/* data transaksi */
 typedef struct 
{
	unsigned char id;				/* ID jenis TCT */
	unsigned char outlet;			/* cabang */
	unsigned char shift;			/* shift pada saat transaksi */
	unsigned char period;			/* periode pada saat transaksi */
	unsigned char location;			/* gerbang pada saat transaksi */
	unsigned char machine;			/* gardu pada saat transaksi */
	unsigned char paket;				/* golongan kendaraan */
	unsigned char payment;			/* metoda pembayaran */
	unsigned char type;          /* jenis transaksi */
	unsigned char cond;				/* kondisi transaksi (NORMAL, AGS, KHL) */
	unsigned char dinas_type;		/* tipe dinas (KTP) */
	unsigned char epayment_status;	/* status transaksi E-TOLL */
	unsigned long long card_id;  /* ID KTME */
	unsigned long long dinas_id;	/* ID kartu DINAS (derek bayar dinas di exit) */
	int tarif;						/* tarif kendaraan */
	int sn;							/* nomor seri transaksi */
	long epayment_balance;			/* saldo E-TOLL setelah transaksi */
	time_t time_ex;					/* waktu transaksi open atau exit */
	time_t open;					/* waktu SOP */
	time_t cycle;					/* waktu siklus shift */
	int kspt;						/* nomor id KPST */
	int pul;						/* nomor id PUL */
	char name[20];					/* nama untuk kartu DINAS */
	char epayment_data[219];		/* data transaksi E-TOLL / BRIZZI / TapCash */
	char epayment_cmd[51];			/* data command transaksi E-TOLL */
	unsigned long long num_card;
	char card_type;
	float	longitude;
	float latitude;
} ELMTscData;

typedef struct
{
	unsigned char shift;	/* nomor shift */
	unsigned char period;	/* nomor periode */
	unsigned char location;	/* nomor gerbang */
	unsigned char machine;	/* nomor gardu */
	unsigned char type;		/* tipe gardu */
	unsigned char dir;		/* arah gardu */
	int outlet;				/* ID cabang toll */
	int sn;					/* nomor transaksi saat ini */
	int sop_online;			/* status online pada saat SOP */
	unsigned int detection; /* deteksi saat transaksi */
	unsigned int reset;		/* jumlah transaksi RESET */
	unsigned int ltn1;		/* LTN 1 (STANDBY) */
	unsigned int ltn2;		/* LTN 2 (SOP) */
	unsigned int ltn3;		/* LTN 3 (TSC) */
	unsigned int ltn4;		/* LTN 4 (MTC) */
	unsigned int test;		/* TEST button pressed */
	unsigned int cart1;		/* ID cartridge #1 */
	unsigned int cart2;		/* ID cartridge #2 */
	int ncart1;				/* jumlah kartu cartridge #1 */
	int ncart2;				/* jumlah kartu cartridge #2 */
	time_t open;			/* SOP time */
	time_t close;			/* EOP time */
	time_t cycle;			/* waktu siklus shift */
	int kspt_id;			/* id PAS */
	int pul_id;				/* id PUL */
	int mtc_id;				/* id TEK */
	char kspt_name[17];		/* nama PAS */
	char pul_name[17];		/* nama PUL */
	char mtc_name[17];		/* name teknisi */
} ELMData;

typedef struct
{
	unsigned char gerbang;
	unsigned char gardu;
	unsigned char shift;
	unsigned char period;
	time_t tm;
	int code;
	int kspt;
	int pul;
} ELMLog;

/* jenis transaksi */
typedef enum
{
	ELM_TRANS_TUNAI_NORMAL	= 1,
	ELM_TRANS_TUNAI_AGS		= 2,
	ELM_TRANS_TUNAI_KHL		= 3,
	ELM_TRANS_UMUM			= 4,
	ELM_TRANS_ETOLL_NORMAL	= 11,
	ELM_TRANS_ETOLL_AGS		= 12,
	ELM_TRANS_BRI_NORMAL	= 14,
	ELM_TRANS_BRI_AGS		= 15,

	ELM_TRANS_BNI_NORMAL	= 16,
	ELM_TRANS_BNI_AGS		= 17,
	ELM_TRANS_BCA_NORMAL	= 18,
	ELM_TRANS_BCA_AGS		= 19,

	ELM_TRANS_DINAS_NORMAL	= 21,
	ELM_TRANS_DINAS_AGS		= 22,
	ELM_TRANS_DINAS_RUSAK	= 24,
	ELM_TRANS_LGN_NORMAL	= 31,
	ELM_TRANS_LGN_AGS		= 32,
	ELM_TRANS_UMUM_NORMAL	= 41,
	ELM_TRANS_NOTRAN_JKR	= 42,
	ELM_TRANS_NOTRAN_KTM	= 80,
	ELM_TRANS_NOTRAN_NONKTM = 81,
	ELM_TRANS_NOTRAN_LSB	= 82,
	ELM_TRANS_NOTRAN_ALR	= 83,
	ELM_TRANS_NOTRAN		= 84,
	ELM_TRANS_TEST			= 91,
	ELM_TRANS_CANCEL		= 92,
	ELM_TRANS_SGOL			= 93,
	ELM_TRANS_DEREK			= 95,
	
	ELM_TRANS_MEMCARD_NORMAL= 151
} ELMTrans;

typedef enum
{
	ELM_DEBUG_INFO = 0, /* informasi */
	ELM_DEBUG_WARNING,	/* peringatan */
	ELM_DEBUG_ERROR,	/* error */
	ELM_DEBUG_FATAL		/* fatal error */
} ELMDebug;


/* buffer data transaksi */
typedef enum
{
	ELM_BUFFER_SETACTIVE = 0,	/* buffer notify ELM aktif ke PCS */
	ELM_BUFFER_NEWOP,			/* buffer new operation */
	ELM_BUFFER_SOP,				/* buffer start of period */
	ELM_BUFFER_EOP,				/* buffer end of period */
	ELM_BUFFER_OPEN,			/* buffer transaksi ELM_OPEN */
	ELM_BUFFER_ENTRY,			/* buffer transaksi ELM_ENTRY */
	ELM_BUFFER_EXIT,			/* buffer transaksi ELM_EXIT */
	ELM_BUFFER_LOG,				/* buffer operasi dan alat ELM */
	ELM_BUFFER_EPAYMENT,		/* buffer data transaksi E-TOLL */
	ELM_BUFFER_EPAYMENT2,
	ELM_BUFFER_VMS,				/* buffer VMS */
	ELM_BUFFER_AVC				/* buffer AVC */
} ELMBuffer;

#define ELM_SCREEN_WIDTH		800
#define ELM_SCREEN_HEIGHT		480

#define ELM_UI_FILE				 		"/var/elm/elm.glade" 
#define ELM_EPAYMENT_FILE				"/var/elm/epayment.conf"
#define ELM_BUFFER_FILE			 		"/var/elm/log/buffer.log"
#define ELM_EPAYMENT_LOG_FILE			"/var/elm/log/etoll.log"
#define ELM_ENTRAN_LOG_FILE				"/var/elm/log/entran.log"
#define ELM_SETTING_FILE				"/var/elm/elm.conf"
#define ELM_COST_FILE					"/var/elm/.cost"
#define ELM_SALDO_KURANG_SOUND			"play	/var/elm/asset/saldo_kurang.mp3"
#define ELM_TRANSAKSI_BERHASIL_SOUND	"play /var/elm/asset/transaksi_berhasil.mp3"
#define ELM_KARTU_TIDAK_DIKENAL_SOUND	"play /var/elm/asset/kartu_tidak_dikenal .mp3"
#define ELM_SN_FILE						"/var/elm/sn.conf"
#define ELM_MEMBERCARD_FILE				"/var/elm/log/.mcfile"

/* main data */
ELMData elm_data;


int elm_debug (ELMDebug, const char*, ...) __attribute__ ((format (printf, 2, 3)));
char* elm_get_idshift (int, int, int, time_t);

int optocoupler_on();
int optocoupler();
#endif /* __ELM_H__ */

