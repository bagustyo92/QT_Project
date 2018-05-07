/*
 * Mandiri E-Toll reader communication module
 *
 * Copyright (C) 2010 - 2012, Delameta Bilano,. Ardhan Madras <ajhwb@knac.com>
 *
 * Last modification: 05/11/2012
 *
 * Protocol format:
 *
 * +----------+----------+-----------+----------+-----------+---------+
 * | START-ID |  HEADER  |   LENGTH  |   DATA   | CHECKSUM  | END-ID  |
 * +----------+----------+-----------+----------+-----------+---------+
 * | 2 bytes  | 7 bytes  |  2 bytes  |  N bytes |  1 byte   | 2 bytes |
 * +----------+----------+-----------+----------+-----------+---------+
 *
 * START-ID  ->  Fixed 2 bytes : 0x10 0x02
 * HEADER    ->  Fixed 7 bytes : 0x08 0x00 0x01 0x00 0x00 0x00 0x00
 * LENGTH    ->  2 bytes
 * DATA      ->  Depends on data context
 * CHECKSUM  ->  By XOR-ing each byte from HEADER to DATA
 * END-ID    ->  Fixed 2 bytes : 0x10 0x03
 *
 */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "elm.h"
#include "enco.h"
#include "elm-enco.h"  
//#include "blackhole.h"

/*
 * Initial protocol data length without the 'data' bytes.
 */
#define INITIAL_PROTO_LEN	14

/*
 * Miliseconds of Mifare card operation timeout
 */
#define MIFARE_IO_TIMEOUT   500

/*
 * Build 32 bit integer as response code start from byte-1
 * of data. The byte-0 is reserved for data code.
 */
#define get_response(s) ((s[12]) << 24 | (s[13]) << 16 | (s[14]) << 8 | (s[15]))


static unsigned int response_code;

#define set_cmd(ctx, data, len) \
do { \
	if (ctx->cmd) \
		free(ctx->cmd); \
	ctx->cmd = (unsigned char*) malloc((len)); \
	ctx->cmd_len = (len); \
	if (ctx->cmd) \
		memcpy(ctx->cmd, (data), (len)); \
} while(0);

#define set_reply(ctx, data, len) \
do { \
	if (ctx->reply) \
		free(ctx->reply); \
	ctx->reply = (unsigned char*) malloc((len)); \
	ctx->reply_len = (len); \
	if (ctx->reply) \
		memcpy(ctx->reply, (data), (len)); \
} while(0);

#define flush() \
do { \
	if (tcflush(ctx->fd, TCIOFLUSH) == -1) { \
		ctx->status = MDR_IO_ERROR; \
		return MDR_ERROR; \
	} \
} while (0);

#define _ETOLL_DEBUG_

struct mdr_ctx {
	int fd;
	int listenfd;
	int cmd_len;
	int reply_len;
	unsigned int status;
	unsigned char *cmd;
	unsigned char *reply;
};

extern int ePayment(char* ,char* ,char* ,char* ,char* ,char* );

/*
 * Possible minimal data length is INITIAL_PROTO_LEN.
 */
static inline int check_lrc(const unsigned char *data, int len)
{
	int i;
	unsigned char lrc = 0;

	if (len < INITIAL_PROTO_LEN)
		return 0;

	for (i = 2; i < len-3; i++)
		lrc ^= data[i];
	if (lrc == data[len-3])
		return 1;
	return 0;
}



#ifdef _ETOLL_DEBUG_
static inline void debug_cmd(const unsigned char *cmd, int len)
{
	int i, data_len;

	data_len = cmd[9] << 16 | cmd[10];

	for (i = 0; i < 11 ; i++)
		if (i < 10)
			fprintf(stderr, "%.2x ", cmd[i]);
		else
			fprintf(stderr, "%.2x | ", cmd[i]);

	for (i = 0; i < data_len; i++)
		if (i < data_len - 1)
			fprintf(stderr, "%.2x ", cmd[i+11]);
		else
			fprintf(stderr, "%.2x | ", cmd[i+11]);

	for (i = 11 + data_len; i < len; i++)
		if (i < len - 1)
			fprintf(stderr, "%.2x ", cmd[i]);
		else
			fprintf(stderr, "%.2x\n", cmd[i]);
}


void debug_cmd2(const unsigned char *cmd, int len)
{
	int i;

	for (i = 0; i < len; i++)
		fprintf(stdout, "%.2x,", cmd[i]);
	puts("");
}
#endif /* _ETOLL_DEBUG_ */

static inline unsigned int reverse_byte(unsigned int x)
{
	unsigned char a = x >> 24 & 0xff;
	unsigned char b = x >> 16 & 0xff;
	unsigned char c = x >> 8 & 0xff;
	unsigned char d = x & 0xff;

	return ((d << 24) | (c << 16) | (b << 8) | a);
}

static inline void ascii_to_bin(const char *str, unsigned char *hex, int len)
{
	char bin[3];
	int i;
	unsigned int x;

	for (i = 0; i < len; i++) {
		sprintf(bin, "%x", str[i]);
		sscanf(bin, "%x", &x);
		hex[i] = x;
	}
}

static inline void bin_to_ascii(unsigned char *hex, char *str, int len)
{
	char ascii[2];
	int i;

	for (i = 0; i < len-1; i++) {
		sprintf(ascii, "%c", hex[i]);
		str[i] = *ascii;
	}
	str[i] = '\0';
}

static inline int read_timeout(int fd, int ms)
{
	struct timeval tv;
	fd_set rset;
	int ret;

	tv = (struct timeval) { 0, ms*1000 };

	while (tv.tv_usec >= 1000000) {
		tv.tv_sec++;
		tv.tv_usec -= 1000000;
	}

	FD_ZERO(&rset);
	FD_SET(fd, &rset);
	ret = select(fd+1, &rset, NULL, NULL, &tv);
	if (ret <= 0) return ret;

	if (FD_ISSET(fd, &rset))
		return ret;
	return -1;
}

static inline unsigned char *build_cmd(unsigned char *data, int data_len, int *cmd_len)
{
	if (data == NULL || data_len <= 0)
		return NULL;

	unsigned char *cmd = (unsigned char *) malloc(INITIAL_PROTO_LEN+data_len);

	if (cmd == NULL) {
		perror(__FILE__);
		return NULL;
	}

	register int i, j;
	unsigned char cksum;


	cmd[0] = 0x10;
	cmd[1] = 0x02;
	cmd[2] = 0x08;
	cmd[3] = 0x00;
	cmd[4] = 0x00;
	cmd[5] = 0x00;
	cmd[6] = 0x00;
	cmd[7] = 0x00;
	cmd[8] = 0x00;
	cmd[9] = data_len >> 8 & 0xff;
	cmd[10] = data_len & 0xff;

	for (i = 11, j = 0; j < data_len; i++, j++)
		cmd[i] = data[j];

	/* Calculate the checksum from header to data */
	cksum = 0;
	for (j = 2; j < i; j++)
		cksum ^= cmd[j];
	cmd[i++] = cksum;

	cmd[i++] = 0x10;
	cmd[i++] = 0x03;

	*cmd_len = i;

	return cmd;
}

mdr_ctx *mdr_init()
{
	
	mdr_ctx *ctx;
	ctx = (mdr_ctx*) malloc(sizeof(mdr_ctx));
	
	ctx->listenfd;
	
	ctx->fd;
	
	  
    struct sockaddr_in serv_addr; // Pakai struct sockaddr_in, sebab pakai AF_INT domainnya
 
    // Ini untuk mendapatkan socket descriptor
    ctx->listenfd = socket(AF_INET, // Connect with different machine 
                      SOCK_STREAM, // TCP connection
                      0); // No additional protocol
    printf("%s : socket retrieve success\n",__func__);
  
    memset(&serv_addr, '0', sizeof(serv_addr));
      
    serv_addr.sin_family = AF_INET; // define the domain used   
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // permit any incoming ip address
    serv_addr.sin_port = htons(5000);  // declare port 5000 to be used  
 
    bind(ctx->listenfd, // Ini adalah socket descriptor 
        (struct sockaddr*)&serv_addr, // Ini adalah struct sockaddr_in (kalau domainnya AF_INET)
        sizeof(serv_addr)); // Ini adalah panjang address
  
    if(listen(ctx->listenfd,// socket descriptor
              10) == -1) // maximum request yang mengantri
    {
        printf("%s : Failed to listen\n",__func__);
        return -1;
    }     
    // Fungsi accept ini akan blocking sampai ada client yang connect : 
    ctx->fd = accept(ctx->listenfd,// socket descriptor
                    (struct sockaddr*)NULL , // no special request to specify address
                    NULL); // sec parameter = NULL, accept awaiting request 




	ctx->cmd = NULL;
	ctx->reply = NULL;

	return ctx;
}

void mdr_free(mdr_ctx *ctx)
{
	close(ctx->fd);
	if (ctx->cmd)
		free(ctx->cmd);
	if (ctx->reply)
		free(ctx->reply);
	free(ctx);
}

int mdr_reset(mdr_ctx *ctx)
{
	int ret;

	ret = tcflush(ctx->fd, TCIOFLUSH);
	if (ret == -1) {
		ctx->status = MDR_IO_ERROR;
		return MDR_ERROR;
	}

	ctx->status = MDR_SUCCESS;

	return MDR_SUCCESS;
}

unsigned int mdr_get_status(mdr_ctx *ctx)
{
	return ctx->status;
}

int mdr_init_sam(mdr_ctx *ctx, const char *pin, const char *ins, const char *termid)
{
	unsigned char data[30];
	unsigned char hex[16];
	unsigned char ans[19];
	unsigned char *cmd;

	size_t bytes = 0;
	int ret, cmd_len;
	register int i, j;


	data[0] = 'H';
	data[1] = '0';

	ascii_to_bin(pin, hex, 16);
	for (i = 2, j = 0; j < 16; j++, i++)
		data[i] = hex[j];

	ascii_to_bin(ins, hex, 4);
	for (j = 0; j < 4; j++, i++)
		data[i] = hex[j];

	ascii_to_bin(termid, hex, 8);
	for (j = 0; j < 8; j++, i++)
		data[i] = hex[j];

	cmd = build_cmd(data, sizeof(data), &cmd_len);

#ifdef _ETOLL_DEBUG_
	fprintf(stderr, "%s tx: ", __func__);
	debug_cmd(cmd, cmd_len);
#endif

	set_cmd(ctx, cmd, cmd_len);
//  //flush();
	ret = write(ctx->fd, cmd+bytes, cmd_len-bytes);
	if (ret == -1) {
		free(cmd);
		return MDR_ERROR;
	}
	free(cmd);
	
	ret = read(ctx->fd, ans+bytes, sizeof(ans)-bytes);
	if (ret == -1) {
		free(cmd);
		ctx->status = MDR_IO_ERROR;
		return MDR_ERROR;
	}

#ifdef _ETOLL_DEBUG_
	fprintf(stderr, "%s rx: ", __func__);
	debug_cmd(ans, sizeof(ans));
#endif

	set_reply(ctx, ans, sizeof(ans));

	if (!check_lrc(ans, sizeof(ans))) {
		ctx->status = MDR_LRC_ERROR;
		return MDR_ERROR;
	}

	ctx->status = get_response(ans);
  if (ctx->status != MDR_SUCCESS)
    return MDR_ERROR;

	return MDR_SUCCESS;
}


/* Himbara BRI init sam */
//int bri_init_sam(mdr_ctx *ctx, const char *mid, const char *tid, const char *shift)
int bri_init_sam(mdr_ctx *ctx, const char *mid, const char *tid, const char *pcode, const char *shift)
{
	unsigned char data[33];
	unsigned char hex[16];
	unsigned char ans[19];
	unsigned char *cmd;

	size_t bytes = 0;
	int ret, cmd_len;
	register int i, j;


	data[0] = 'H';
	data[1] = '1';

	ascii_to_bin(mid, hex, 15);
	for (i = 2, j = 0; j < 15; j++, i++)
		data[i] = hex[j];

	ascii_to_bin(tid, hex, 8);
	for (j = 0; j < 8; j++, i++)
		data[i] = hex[j];

	ascii_to_bin(shift, hex,2);
	for (j = 0; j < 2; j++, i++)
		data[i] = hex[j];
  /* procode */
	ascii_to_bin(pcode, hex,6);
	for (j = 0; j < 6; j++, i++)
		data[i] = hex[j];

	cmd = build_cmd(data, sizeof(data), &cmd_len);

#ifdef _ETOLL_DEBUG_
	fprintf(stderr, "%s tx: ", __func__);
	debug_cmd(cmd, cmd_len);
#endif

	set_cmd(ctx, cmd, cmd_len);
//  //flush();
		ret = write(ctx->fd, cmd+bytes, cmd_len-bytes);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}

	free(cmd);


		ret = read(ctx->fd, ans+bytes, sizeof(ans)-bytes);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}

#ifdef _ETOLL_DEBUG_
	fprintf(stderr, "%s rx: ", __func__);
	debug_cmd(ans, sizeof(ans));
#endif

	set_reply(ctx, ans, sizeof(ans));

	if (!check_lrc(ans, sizeof(ans))) {
		ctx->status = MDR_LRC_ERROR;
		return MDR_ERROR;
	}

	ctx->status = get_response(ans);
  if (ctx->status != MDR_SUCCESS)
    return MDR_ERROR;

	return MDR_SUCCESS;
}
/* Himbara BNI init sam */
int bni_init_sam(mdr_ctx *ctx, const char *tid)
{
	unsigned char data[10];
	unsigned char hex[16];
	unsigned char ans[19];
	unsigned char *cmd;

	size_t bytes = 0;
	int ret, cmd_len;
	register int i, j;


	data[0] = 'H';
	data[1] = '2';

	ascii_to_bin(tid, hex, 8);
	for (i = 2, j = 0; j < 8; j++, i++)
		data[i] = hex[j];

	cmd = build_cmd(data, sizeof(data), &cmd_len);

#ifdef _ETOLL_DEBUG_
	fprintf(stderr, "%s tx: ", __func__);
	debug_cmd(cmd, cmd_len);
#endif

	set_cmd(ctx, cmd, cmd_len);
//  //flush();
	ret = write(ctx->fd, cmd+bytes, cmd_len-bytes);
	if (ret == -1) {
		free(cmd);
		ctx->status = MDR_IO_ERROR;
		return MDR_ERROR;
	}

	free(cmd);

	ret = read_timeout(ctx->fd, 2000);
	if (ret == -1) {
		ctx->status = MDR_IO_ERROR;
		return MDR_ERROR;
	}
	if (ret == 0) {
		ctx->status = MDR_TIMEOUT;
		return MDR_ERROR;
	}

	ret = read(ctx->fd, ans+bytes, sizeof(ans)-bytes);
	if (ret == -1) {
		free(cmd);
		ctx->status = MDR_IO_ERROR;
		return MDR_ERROR;
	}
	
#ifdef _ETOLL_DEBUG_
	fprintf(stderr, "%s rx: ", __func__);
	debug_cmd(ans, sizeof(ans));
#endif

	set_reply(ctx, ans, sizeof(ans));

	if (!check_lrc(ans, sizeof(ans))) {
		ctx->status = MDR_LRC_ERROR;
		return MDR_ERROR;
	}

	ctx->status = get_response(ans);
  if (ctx->status != MDR_SUCCESS)
    return MDR_ERROR;

	return MDR_SUCCESS;
}

/* Himbara BCA init sam */
int bca_init_sam(mdr_ctx *ctx, const char *mid, const char *tid)
{
	unsigned char data[22];
	unsigned char hex[16];
	unsigned char ans[19];
	unsigned char *cmd;

	size_t bytes = 0;
	int ret, cmd_len;
	register int i, j;


	data[0] = 'H';
	data[1] = '3';

	ascii_to_bin(tid, hex, 8);
	for (i = 2, j = 0; j < 8; j++, i++)
		data[i] = hex[j];

	ascii_to_bin(mid, hex, 12);
	for (j = 0; j < 12; j++, i++)
		data[i] = hex[j];

	cmd = build_cmd(data, sizeof(data), &cmd_len);

#ifdef _ETOLL_DEBUG_
	fprintf(stderr, "%s tx: ", __func__);
	debug_cmd(cmd, cmd_len);
#endif

	set_cmd(ctx, cmd, cmd_len);

	ret = write(ctx->fd, cmd+bytes, cmd_len-bytes);
	if (ret == -1) {
		free(cmd);
		ctx->status = MDR_IO_ERROR;
		return MDR_ERROR;
	}
	free(cmd);


	ret = read(ctx->fd, ans+bytes, sizeof(ans)-bytes);
	if (ret == -1) {
		free(cmd);
		ctx->status = MDR_IO_ERROR;
		return MDR_ERROR;
	}

#ifdef _ETOLL_DEBUG_
	fprintf(stderr, "%s rx: ", __func__);
	debug_cmd(ans, sizeof(ans));
#endif

	set_reply(ctx, ans, sizeof(ans));

	if (!check_lrc(ans, sizeof(ans))) {
		ctx->status = MDR_LRC_ERROR;
		return MDR_ERROR;
	}

	ctx->status = get_response(ans);
	if (ctx->status != MDR_SUCCESS)
		return MDR_ERROR;

	return MDR_SUCCESS;
}

int mdr_inq_balance(mdr_ctx *ctx, unsigned long long *balance, int timeout)
{
	char date_time[13];
	char timeout_str[4];
	char balance_str[11];

	unsigned char data[16];
	unsigned char hex[12];
	unsigned char ans[INITIAL_PROTO_LEN+31];
	unsigned char *cmd;

	int ret, cmd_len, data_len;
	int check = 0;
	size_t bytes = 0, len;
	time_t current_time = time(NULL);
	struct tm *st;

	register int i, j;


	st = localtime(&current_time);

	sprintf(date_time, "%.2i%.2i%.2i%.2i%.2i%.2i", 
			st->tm_mday, st->tm_mon+1, (st->tm_year + 1900) % 100,
			st->tm_hour, st->tm_min, st->tm_sec);

	snprintf(timeout_str, sizeof(timeout_str), "%.3i", timeout);

	data[0] = 0x31;

	ascii_to_bin(date_time, hex, 12);
	for (i = 1, j = 0; j < 12; j++, i++)
		data[i] = hex[j];

	ascii_to_bin(timeout_str, hex, 3);
	for (j = 0; j < 3; j++, i++)
		data[i] = hex[j];

	cmd = build_cmd(data, sizeof(data), &cmd_len);

#ifdef _ETOLL_DEBUG
	fprintf(stderr, "%s tx: ", __func__);
	debug_cmd(cmd, cmd_len);
#endif

	set_cmd(ctx, cmd, cmd_len);

		ret = write(ctx->fd, cmd+bytes, cmd_len-bytes);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		bytes += ret;

	free(cmd);

	/*
	 * Balance inquiry avarage processing time is 972ms,
	 * we give 1100ms for read timeout, see purchase_debt() 
	 * for more details.
	 */
	bytes = 0;
	len = sizeof(ans);
	
		ret = read(ctx->fd, ans+bytes, len-bytes);
		if (ret == -1) {
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}

			data_len = ans[9] << 16 | ans[10];
			len = INITIAL_PROTO_LEN+data_len;
			if (len > sizeof(ans)) {
				ctx->status = MDR_IO_ERROR;
				return MDR_ERROR;
			}

#ifdef _ETOLL_DEBUG
	fprintf(stderr, "%s rx: ", __func__);
	debug_cmd(ans, len);
#endif


	set_reply(ctx, ans, len);

	if (!check_lrc(ans, len)) {
		ctx->status = MDR_LRC_ERROR;
		return MDR_ERROR;
	}

	ctx->status = get_response(ans);

	if (ctx->status == MDR_SUCCESS && balance != NULL) {
		bin_to_ascii(ans+16, balance_str, sizeof(balance_str));
		*balance = strtoul(balance_str, NULL, 10);
	}

	return MDR_SUCCESS;
}

/* update 12-09-1013
 * perubahan :
 * command code  0x32 -> 0x44
 * responde data 94 bytes -> 26 bytes
 * 26 bytes = balance amount 10 bytes + No kartu 16 bytes
 */ 
int mdr_purchase_debt(mdr_ctx *ctx, unsigned long amount, time_t tsc_time,
			int timeout, unsigned char *tsc_report, struct mdr_etoll2 *etoll)
{
	unsigned char *cmd;
	unsigned char data[26];
	unsigned char hex[12];
//	unsigned char ans[INITIAL_PROTO_LEN+255];
//	unsigned char ans[INITIAL_PROTO_LEN+99];
	unsigned char ans[INITIAL_PROTO_LEN+35];

	char date_str[13];
	char amount_str[11];
	char timeout_str[4];
	char str[17];

	time_t current_time;
	struct tm *st;
	int ret;
	int cmd_len, data_len;
	int check = 0;
	size_t bytes = 0;
	size_t len;//,max_ans = INITIAL_PROTO_LEN+77;
        
	register int i, j;


	current_time = (tsc_time == 0) ? time (NULL) : tsc_time;
	st = localtime(&current_time);

	sprintf(date_str, "%.2i%.2i%.2i%.2i%.2i%.2i",
			st->tm_mday, st->tm_mon+1, (st->tm_year + 1900) % 100,
			st->tm_hour, st->tm_min, st->tm_sec);

	snprintf(amount_str, sizeof(amount_str), "%.10lu", amount);
	snprintf(timeout_str, sizeof(timeout_str), "%.3i", timeout);


	data[0] = 0x44; //0x32;

	ascii_to_bin(date_str, hex, 12);
	for (i = 1, j = 0; j < 12; i++, j++)
		data[i] = hex[j];

	ascii_to_bin(amount_str, hex, 10);
	for (j = 0; j < 10; j++, i++)
		data[i] = hex[j];

	ascii_to_bin(timeout_str, hex, 3);
	for (j = 0; j < 3; j++, i++)
		data[i] = hex[j];

	cmd = build_cmd(data, sizeof(data), &cmd_len);


#ifdef _ETOLL_DEBUG_
	fprintf(stderr,"%s tx: ", __func__);
	debug_cmd(cmd, cmd_len);
#endif
	set_cmd(ctx, cmd, cmd_len);

	if (cmd_len >= 12+sizeof etoll->e1.tsc_cmd)
		memcpy(etoll->e1.tsc_cmd, cmd+12, sizeof etoll->e1.tsc_cmd);

//  //flush();	
	while (bytes < cmd_len) {
		ret = write(ctx->fd, cmd+bytes, cmd_len-bytes);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		bytes += ret;
	}

	/*
	 *
	 */
	bytes = 0;
	len = sizeof(ans);
	while (bytes < len) {
		ret = read_timeout(ctx->fd, 5000);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		} else if (ret == 0) {
			free(cmd);
			ctx->status = MDR_TIMEOUT;			
			return MDR_TIMEOUT;
		}

		ret = read(ctx->fd, ans+bytes, len-bytes);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		bytes += ret;

		if (bytes > 10 && check == 0) {
			data_len = ans[9] << 16 | ans[10];
			len = INITIAL_PROTO_LEN+data_len;
			check ^= 1;
		}
	}

	if (len > sizeof(ans)) {
		fprintf(stderr, "%s: invalid reply length\n", __func__);
		free(cmd);
		ctx->status = MDR_IO_ERROR;
		return MDR_ERROR;
	}

#ifdef _ETOLL_DEBUG_
	fprintf(stderr,"%s rx: ", __func__);
	debug_cmd(ans, len);
	fprintf(stderr, "%s ==> %c%c%c%c%c\n", __func__,
			isdigit(ans[11]) ? ans[11] : '.', 
			isdigit(ans[12]) ? ans[12] : '.',
			isdigit(ans[13]) ? ans[13] : '.',
			isdigit(ans[14]) ? ans[14] : '.',
			isdigit(ans[15]) ? ans[15] : '.');
#endif
	set_reply(ctx, ans, len);

	if (!check_lrc(ans, len)) {
		fprintf(stdout, "%s lrc error\n", __func__);
		free(cmd);
		ctx->status = MDR_LRC_ERROR;
		return MDR_ERROR;
	}

	ctx->status = get_response(ans);

	if (ans[11] != 0x44)
    {
      fprintf(stdout, "%s 0x%X reply code error\n", __func__,ans[11]);
      free(cmd);
		  ctx->status = MDR_IO_ERROR;
	    return MDR_ERROR;
	  }

	if (ctx->status == MDR_PURCHASE_CORRECTION)
	  memcpy(tsc_report, ans+16, 26);

	if (ctx->status != MDR_SUCCESS)
    {
	    free(cmd);
	    return MDR_SUCCESS;
	  }

	memcpy(tsc_report, ans+16, 26);
  memcpy(str,tsc_report, 10);
  str[10]=0;
	etoll->e1.last_balance = strtoul(str, NULL, 10);

	free(cmd);

	return MDR_SUCCESS;
}


int mdr2_purchase_debt(mdr_ctx *ctx, unsigned long amount, time_t tsc_time,
			int timeout, unsigned char *tsc_report, struct mdr_etoll2 *etoll)
{
	unsigned char *cmd;
	unsigned char data[26];
	unsigned char hex[12];
	unsigned char ans[INITIAL_PROTO_LEN+255];

	char date_str[13];
	char amount_str[11];
	char timeout_str[4];
	char str[17];

	time_t current_time;
	struct tm *st;
	int ret;
	int cmd_len, data_len;
	int check = 0;
	size_t bytes = 0;
	size_t len,max_ans = INITIAL_PROTO_LEN+77;
        
	register int i, j;


	current_time = (tsc_time == 0) ? time (NULL) : tsc_time;
	st = localtime(&current_time);

	sprintf(date_str, "%.2i%.2i%.2i%.2i%.2i%.2i",
			st->tm_mday, st->tm_mon+1, (st->tm_year + 1900) % 100,
			st->tm_hour, st->tm_min, st->tm_sec);

	snprintf(amount_str, sizeof(amount_str), "%.10lu", amount);
	snprintf(timeout_str, sizeof(timeout_str), "%.3i", timeout);


	data[0] = 0x46;

	ascii_to_bin(date_str, hex, 12);
	for (i = 1, j = 0; j < 12; i++, j++)
		data[i] = hex[j];

	ascii_to_bin(amount_str, hex, 10);
	for (j = 0; j < 10; j++, i++)
		data[i] = hex[j];

	ascii_to_bin(timeout_str, hex, 3);
	for (j = 0; j < 3; j++, i++)
		data[i] = hex[j];

	cmd = build_cmd(data, sizeof(data), &cmd_len);


#ifdef _ETOLL_DEBUG
	fprintf(stderr,"%s tx: ", __func__);
	debug_cmd(cmd, cmd_len);
#endif
	set_cmd(ctx, cmd, cmd_len);

//  //flush();	
		ret = write(ctx->fd, cmd+bytes, cmd_len-bytes);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
	/*
	 * Since this require operation timeout, we should
	 * provide larger read_timeout() time as well.
	 * The reader extends its processing time when card is
	 * detected, consider we have requested 1000ms processing
	 * timeout, then at 800th ms card is detected and being
	 * processed. There are no documentation that describe
	 * this timing, but basic on my test shows that processing 
	 * time is averaged at 1870ms, for purchase_debt().
	 *
	 * Another reader 2000ms isn't enough, we provide 5000ms 
	 * additional timeout, should make most reader happy.
	 */
	bytes = 0;
	len = max_ans; //sizeof(ans);
	while (bytes < len) {
		ret = read_timeout(ctx->fd, 5000);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		} else if (ret == 0) {
			free(cmd);
			ctx->status = MDR_TIMEOUT;			
			return MDR_TIMEOUT;
		}

		ret = read(ctx->fd, ans+bytes, len-bytes);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		bytes += ret;

		if (bytes > 10 && check == 0) {
			data_len = ans[9] << 16 | ans[10];
			len = INITIAL_PROTO_LEN+data_len;
			check ^= 1;
		}
	}
  //fprintf(stderr,"%s: %d bytes ans\n",__func__,bytes);
	if (len > sizeof(ans)) {
		fprintf(stderr, "%s: invalid reply length\n", __func__);
		free(cmd);
		ctx->status = MDR_IO_ERROR;
		return MDR_ERROR;
	}

#ifdef _ETOLL_DEBUG
	fprintf(stderr,"%s rx: ", __func__);
	debug_cmd(ans, len);
	fprintf(stderr, "%s ==> %c%c%c%c%c %c\n", __func__,
			isdigit(ans[11]) ? ans[11] : '.', 
			isdigit(ans[12]) ? ans[12] : '.',
			isdigit(ans[13]) ? ans[13] : '.',
			isdigit(ans[14]) ? ans[14] : '.',
			isdigit(ans[15]) ? ans[15] : '.',
			isdigit(ans[16]) ? ans[16] : '.');
#endif
	set_reply(ctx, ans, len);

	if (!check_lrc(ans, len)) {
		fprintf(stdout, "%s lrc error\n", __func__);
		free(cmd);
		ctx->status = MDR_LRC_ERROR;
		return MDR_ERROR;
	}

	ctx->status = get_response(ans);

	if (ans[11] != 0x46)
    {
      fprintf(stdout, "%s 0x%X reply code error\n", __func__,ans[11]);
      free(cmd);
		  ctx->status = MDR_IO_ERROR;
	    return MDR_ERROR;
	  }

	if (ctx->status != MDR_SUCCESS)
    {
      if (ctx->status == MDR_PURCHASE_CORRECTION)
   	    memcpy(tsc_report, ans+16, 16);
     
	    free(cmd);
	    return MDR_SUCCESS;
	  }

  if (ans[16] == MANDIRI_CARD)
    {
      ans[43] =0;
	    memcpy(tsc_report, ans+17, 43);
	    
	    memcpy(str, ans+17, 10);
	    str[10]=0;
	    etoll->e1.last_balance = strtoul(str, NULL, 10);

	    memcpy(str, ans+27, 17);
	    str[16]=0;
	    etoll->card_num = strtoull(str, NULL, 10);
      etoll->card_id = MANDIRI_CARD;
      //fprintf(stderr,"%s: %llu , bal %lu\n",
      //                __func__,etoll->card_num, etoll->e1.last_balance);
    }
  else if (ans[16] == BRI_JAVA_CARD)
    {
	    memcpy(tsc_report, ans+17, 71);

	    bin_to_ascii(tsc_report+55, str, 9);
	    etoll->e1.last_balance = strtoul(str, NULL, 16);
	    etoll->e1.last_balance = reverse_byte(etoll->e1.last_balance);

	    bin_to_ascii(tsc_report+18, str, 9);
	    etoll->card_num = strtoull(str, NULL, 10);	    
      etoll->card_id = BRI_JAVA_CARD;
    }
  else if (ans[16] == BRI_DESFIRE_CARD)
    {
	    memcpy(tsc_report, ans+17, 87);

	    bin_to_ascii(tsc_report+78, str, 10);   
	    etoll->e1.last_balance = strtoul(str, NULL, 16);

	    bin_to_ascii(tsc_report+18, str, 9);
	    etoll->card_num = strtoull(str, NULL, 10);
      etoll->card_id = BRI_DESFIRE_CARD;
    }
  else if (ans[16] == BNI_CARD)
    {
	    memcpy(tsc_report, ans+17, 218);
	    memcpy(str, ans+20, 17);
	    str[16]=0;
	    etoll->card_num = strtoull(str, NULL, 10);
      etoll->card_id = BNI_CARD;
    }
  else if (ans[16] == BCA_CARD)
    {
	    memcpy(tsc_report, ans+17, 189);
	    memcpy(str, ans+20, 17);
	    str[16]=0;
	    etoll->card_num = strtoull(str, NULL, 10);

	    bin_to_ascii(tsc_report+40, str, 10);
	    etoll->e1.last_balance = strtoul(str, NULL, 16);
      etoll->card_id = BCA_CARD;
    }
  else
    {
      fprintf(stdout, "%s 0x%X unknown card\n", __func__,ans[16]);
      free(cmd);
		  ctx->status = MDR_IO_ERROR;
	    return MDR_ERROR;  
    }

  //fprintf(stderr,"%s: %llu, amount %lu,  bal %lu\n",
  //               __func__,etoll->card_num, etoll->e1.tsc_amount, etoll->e1.last_balance);

	/*
	 * Copy command's data information, we have 25 bytes for
	 * date, amount and operation timeout.
	 */
	if (cmd_len >= 12+sizeof etoll->e1.tsc_cmd)
		memcpy(etoll->e1.tsc_cmd, cmd+12, sizeof etoll->e1.tsc_cmd);

  //etoll->e1.tsc_cmd[24]=0;
  //fprintf(stderr,"%s: cmd %s\n",__func__,etoll->e1.tsc_cmd);

	free(cmd);

	return MDR_SUCCESS;
}


int mdr_get_report(mdr_ctx *ctx, unsigned char *tsc_report)
{
	unsigned char *cmd;
	unsigned char data;
	unsigned char ans[INITIAL_PROTO_LEN+99];

	int ret, cmd_len;
	size_t bytes = 0;


	data = 0x33;

	cmd = build_cmd(&data, 1, &cmd_len);

#ifdef _ETOLL_DEBUG
	fprintf(stderr, "%s tx: ", __func__);
	debug_cmd(cmd, cmd_len);
#endif

	set_cmd(ctx, cmd, cmd_len);
  //flush();
	while (bytes < cmd_len) {
		ret = write(ctx->fd, cmd+bytes, cmd_len-bytes);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		bytes += ret;
	}

	free(cmd);

	bytes = 0;
	while (bytes < sizeof(ans)) {
		ret = read_timeout(ctx->fd, 2000);
		if (ret == -1) {
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		if (ret == 0) {
			ctx->status = MDR_TIMEOUT;
			return MDR_ERROR;
		}
		ret = read(ctx->fd, ans+bytes, sizeof(ans)-bytes);
		if (ret == -1) {
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		bytes += ret;
	}

#ifdef _ETOLL_DEBUG
	fprintf(stderr, "%s rx: ", __func__);
	debug_cmd(ans, sizeof(ans));
#endif

	set_reply(ctx, ans, sizeof(ans));

	if (!check_lrc(ans, sizeof(ans))) {
		ctx->status = MDR_LRC_ERROR;
		return MDR_ERROR;
	}

	ctx->status = get_response(ans);

	if (ctx->status == MDR_SUCCESS && tsc_report)
		memcpy(tsc_report, ans+16, 94);

	return MDR_SUCCESS;
}

/**
 * get report transaksi eToll, BRIZZI, TapCash BNI, BCA Flazz
 *
 *
 */
int mdr2_get_report(mdr_ctx *ctx, unsigned char *tsc_report, int *e_id)
{
	unsigned char *cmd;
	unsigned char data;
	unsigned char ans[512];//INITIAL_PROTO_LEN+99];

	int ret, cmd_len;
	int data_len=0,check=0;
	int len,size_ans=512;//71; /* default BRI, size terkecil */
	size_t bytes = 0;


	data = 0x47;

	cmd = build_cmd(&data, 1, &cmd_len);

#ifdef _ETOLL_DEBUG_
	fprintf(stderr, "%s tx: ", __func__);
	debug_cmd(cmd, cmd_len);
#endif

//  flush();
	set_cmd(ctx, cmd, cmd_len);
  
		ret = write(ctx->fd, cmd+bytes, cmd_len-bytes);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}

	free(cmd);
		len =size_ans;
	
		ret = read(ctx->fd, ans, len);
		if (ret == -1) {
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
			data_len = ans[9] << 16 | ans[10];
			len = INITIAL_PROTO_LEN+data_len;
			check ^= 1;

#ifdef _ETOLL_DEBUG_
	fprintf(stderr,"%s rx: ", __func__);
	debug_cmd(ans, len);
	fprintf(stderr, "%s ==> %c%c%c%c%c%c\n", __func__,
			isdigit(ans[11]) ? ans[11] : '.', 
			isdigit(ans[12]) ? ans[12] : '.',
			isdigit(ans[13]) ? ans[13] : '.',
			isdigit(ans[14]) ? ans[14] : '.',
			isdigit(ans[15]) ? ans[15] : '.',
			isdigit(ans[16]) ? ans[16] : '.');			
#endif

	set_reply(ctx, ans, sizeof(ans));

	if (!check_lrc(ans, len)) {
		fprintf(stderr, "%s: lrc error\n", __func__);
		ctx->status = MDR_LRC_ERROR;
		return MDR_ERROR;
	}

	ctx->status = get_response(ans);

	if (ans[11] != 0x47)
    {
      fprintf(stdout, "%s 0x%X reply code error\n", __func__,ans[11]);
		  ctx->status = MDR_REPLYCODE_ERROR;
	    return MDR_ERROR;
	  }
	
  fprintf(stderr, "%s: data_len %d %d %x\n",
                   __func__,data_len,data_len-6,ans[16]);

	if (ctx->status == MDR_SUCCESS)
	  {
		  memcpy(tsc_report, ans+17, data_len-6);  
			tsc_report[data_len-6]=0;
    }
  *e_id = ans[16];
	return MDR_SUCCESS;
}



unsigned int mdr_get_response(void)
{
	return response_code;
}

int mdr_cancel_debt(mdr_ctx *ctx)
{
	unsigned char *cmd;
	unsigned char data;
	unsigned char ans[INITIAL_PROTO_LEN+35];

	int ret, cmd_len, data_len;
	int check = 1;
	size_t bytes = 0, ans_len;

	data = 0x42;

	cmd = build_cmd(&data, 1, &cmd_len);

#ifdef _ETOLL_DEBUG_
	fprintf(stderr, "%s tx: ", __func__);
	debug_cmd(cmd, cmd_len);
#endif

	set_cmd(ctx, cmd, cmd_len);

	while (bytes < cmd_len) {
		ret = write(ctx->fd, cmd+bytes, cmd_len-bytes);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		bytes += ret;
	}

	free(cmd);

	bytes = 0;
	ans_len = sizeof(ans);

	while (bytes < ans_len) {
		ret = read_timeout(ctx->fd, 1000);
		if (ret == -1) {
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		else if (ret == 0) {
			ctx->status = MDR_TIMEOUT;
			return MDR_ERROR;
		}

		ret = read(ctx->fd, ans+bytes, ans_len-bytes);
		if (ret <= 0) {
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		bytes += ret;

		/*
		 * Data length is depends on answer context, so we make sure
		 * to update data length after we got length's information bytes.
 		 */
		if (check && bytes > 10) {
			data_len = ans[9] << 8 | ans[10];
			ans_len = INITIAL_PROTO_LEN+data_len;
			if (ans_len > sizeof(ans)) {
				ctx->status = MDR_IO_ERROR;
				return MDR_ERROR;
			}
			check ^= 1;
		}
	}

#ifdef _ETOLL_DEBUG_
	fprintf(stderr, "%s rx: ", __func__);
	debug_cmd(ans, ans_len);
#endif

	set_reply(ctx, ans, ans_len);

	/*
	 * The LRC check for data that has 5 bytes length is miscalculated :-)
	 * yes, Mandiri sucks.
	 */
	if (!check_lrc(ans, ans_len)) {
		ctx->status = MDR_LRC_ERROR;
		return MDR_ERROR;
	}

	ctx->status = get_response(ans);

	return MDR_SUCCESS;
}


int mdr_get_cmd(mdr_ctx *ctx, const unsigned char **output, int *len)
{
	if (ctx) {
		*output = ctx->cmd;
		*len = ctx->cmd_len;
    /*
		fprintf(stderr,"-> %s \n",*output);
		                   *output[0],*output[1],*output[2],*output[3],
		                   *output[4],*output[5],*output[6]);
		 */                  
		return MDR_SUCCESS;
	} else {
		return MDR_ERROR;
	}
}

int mdr_get_reply(mdr_ctx *ctx, const unsigned char **output, int *len)
{
	if (ctx) {
		*output = ctx->reply;
		*len = ctx->reply_len;
		return MDR_SUCCESS;
	} else {
		return MDR_ERROR;
	}
}

int mdr2_get_cardnumber(mdr_ctx *ctx, int flag, int timeout, unsigned long long *cardnum, char *id)
{
	char flag_str[2];
	char timeout_str[4];
  char cardnum_str[17];
 
	unsigned char data[5];
	unsigned char hex[12];
	unsigned char ans[512];
	unsigned char *cmd;

	int ret, cmd_len, data_len;
	int valid_ans=45;
	int check = 0;
	size_t bytes = 0, len;
	register int i, j;


	data[0] = 0x43;

  snprintf(flag_str, sizeof(flag_str), "%.1i", flag);
	ascii_to_bin(flag_str, hex, 1);	
	for (i = 1, j = 0; j < 1; i++, j++)
	     data[i] = hex[j];

  snprintf(timeout_str, sizeof(timeout_str), "%.3i", timeout);
	ascii_to_bin(timeout_str, hex, 3);
	for (j = 0; j < 3; j++, i++)
		data[i] = hex[j];

	cmd = build_cmd(data, sizeof(data), &cmd_len);

#ifdef _ETOLL_DEBUG
	fprintf(stderr,"%s tx: ", __func__);
	debug_cmd(cmd, cmd_len);
#endif
	set_cmd(ctx, cmd, cmd_len);

  //flush();
	while (bytes < cmd_len) {
		ret = write(ctx->fd, cmd+bytes, cmd_len-bytes);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		bytes += ret;
	}

	free(cmd);

	/*
   *
 	 */
	bytes = 0;
	len = valid_ans;//sizeof(ans);
	while (bytes < len) {
		ret = read_timeout(ctx->fd, 2000);
		if (ret == -1) {
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		else if (ret == 0) {
			ctx->status = MDR_TIMEOUT;
		  return MDR_ERROR;
    }

		ret = read(ctx->fd, ans+bytes, len-bytes);
		if (ret == -1) {
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		bytes += ret;

		if (bytes > 10 && check == 0) {
			data_len = ans[9] << 16 | ans[10];
			len = INITIAL_PROTO_LEN+data_len;
			check ^= 1;
		}
	}

	if (len > valid_ans)
	  {
		 fprintf(stderr, "%s: invalid reply length %d bytes\n", __func__, len);
		 ctx->status = MDR_IO_ERROR;
		 return MDR_ERROR;
	  }

#ifdef _ETOLL_DEBUG
	fprintf(stderr,"%s rx: ", __func__);
	debug_cmd(ans, len);
	fprintf(stderr, "%s ==> %c%c%c%c%c\n", __func__,
			isdigit(ans[11]) ? ans[11] : '.', 
			isdigit(ans[12]) ? ans[12] : '.',
			isdigit(ans[13]) ? ans[13] : '.',
			isdigit(ans[14]) ? ans[14] : '.',
			isdigit(ans[15]) ? ans[15] : '.');
#endif

	set_reply(ctx, ans, len);

	if (!check_lrc(ans, len)) {
		fprintf(stderr, "%s: lrc error\n", __func__);
		ctx->status = MDR_LRC_ERROR;
		return MDR_ERROR;
	}

	ctx->status = get_response(ans);

	if (ctx->status == MDR_SUCCESS) {
		  bin_to_ascii(ans+16, cardnum_str, sizeof(cardnum_str));
		 *cardnum = strtoull(cardnum_str, NULL, 10);
     *id = ans[32];

		  if (flag == 2)
		    fprintf(stderr, "%s: %s\n", __func__,cardnum_str);
		  return MDR_SUCCESS;
	}

	return MDR_ERROR;
}

int mdr2_set_sam_slot(mdr_ctx *ctx,char slot1, char slot2, char slot3,  char slot4, int timeout)
{
	char timeout_str[4];
 
	unsigned char data[10];
	unsigned char hex[12];
	unsigned char ans[INITIAL_PROTO_LEN+7];
	unsigned char *cmd;

	int ret, cmd_len, data_len;
	int valid_ans = sizeof ans;
	int check = 0;
	size_t bytes = 0, len;
	register int i, j;


	data[0] = 'H';
	data[1] = 'A';
	data[2] = '1';
	data[3] = slot1;
	data[4] = slot2;
	data[5] = slot3;
	data[6] = slot4;

  i=7;
	snprintf(timeout_str, sizeof(timeout_str), "%.3i", timeout);
	ascii_to_bin(timeout_str, hex, 3);
	for (j = 0; j < 3; j++, i++)
		data[i] = hex[j];

	cmd = build_cmd(data, sizeof(data), &cmd_len);

#ifdef _ETOLL_DEBUG_
	printf("%s tx: ", __func__);
	debug_cmd(cmd, cmd_len);
#endif

  //flush();
	while (bytes < cmd_len) {
		ret = write(ctx->fd, cmd+bytes, cmd_len-bytes);
		if (ret == -1) {
			free(cmd);
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		bytes += ret;
	}

	free(cmd);

	bytes = 0;
	len = valid_ans;
	while (bytes < len) {
  	ret = read_timeout(ctx->fd, 2000);
		if (ret == -1) {
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		else if (ret == 0) {
			ctx->status = MDR_TIMEOUT;
		  return MDR_ERROR;
    }

		ret = read(ctx->fd, ans+bytes, len-bytes);
		if (ret == -1) {
			ctx->status = MDR_IO_ERROR;
			return MDR_ERROR;
		}
		bytes += ret;

		if (bytes > 10 && check == 0) {
			data_len = ans[9] << 16 | ans[10];
			len = INITIAL_PROTO_LEN+data_len;
			check ^= 1;
		}
	}

	if (len > valid_ans)
	  {
		  fprintf(stderr, "%s: invalid reply length %d bytes\n", __func__, len);
		  ctx->status = MDR_IO_ERROR;
		  return MDR_ERROR;
	  }

#ifdef _ETOLL_DEBUG_
	printf("%s rx: ", __func__);
	debug_cmd(ans, len);
	fprintf(stderr, "%s ==> %c%c%c%c%c\n", __func__,
			isdigit(ans[11]) ? ans[11] : '.', 
			isdigit(ans[12]) ? ans[12] : '.',
			isdigit(ans[13]) ? ans[13] : '.',
			isdigit(ans[14]) ? ans[14] : '.',
			isdigit(ans[15]) ? ans[15] : '.');
#endif

	if (!check_lrc(ans, len)) {
		fprintf(stderr, "%s: lrc error\n", __func__);
		ctx->status = MDR_LRC_ERROR;
		return MDR_ERROR;
	}

	ctx->status = get_response(ans);
  fprintf(stderr, "%s: %x\n", __func__,ctx->status);

	if (ctx->status == 0x30303132)
	  {
		  return MDR_SUCCESS;
	  }

	return MDR_ERROR;
}
