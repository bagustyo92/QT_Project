#ifndef __ELM_UTILS_H__
#define __ELM_UTILS_H__

#include <glib.h>
#include <time.h>
#include <arpa/inet.h>

char* get_time (time_t*);
char* get_date (time_t*);
char* get_date_day (time_t*);
char* get_dated_slash (time_t*);
char* get_dated_dash (time_t*);
char* get_datey_dash (time_t*);
char* bin2str (unsigned int, int);
unsigned int str2bin (const char*);
gboolean send_udp_data (void*, size_t, const char*, int);
ssize_t receive_udp_data (int, void*, size_t, int, struct sockaddr_in*);

#endif
