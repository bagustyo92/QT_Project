#ifndef __ELM_GUI_H__
#define __ELM_GUI_H__
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <glib.h>
#include <glib/gprintf.h>
#include "elm.h"

	
struct Enco
{
	int run;
	int listenfd;
	int connfd;
	char receiveBuff[1025];  
	int numrv;  
	int fd;
	int cmd_len;
	int reply_len;
	unsigned char status[4];
	unsigned char *cmd;
	unsigned char *reply;
};
	 
	char sccardnumber[16];
	char scbalance[10];
	char sctype[10];


GThread *ENCOThread;
GMutex *mutexelm;
GCond *condelm; 



int enco_open(void);
int enco_start(void);
int enco_stop(void);
void* enco_thread(void *data);
gboolean enco_get_cardnumber(char cmd, unsigned long long* num, char* id);
int enco_purchase_debit(void);
int enco_get_balance(void);
gboolean mandiri_sam_init(void);
gboolean bri_sam_init(void);
gboolean bca_sam_init(void);
gboolean bni_sam_init(void);
int bank_sam_init(void);


#endif
