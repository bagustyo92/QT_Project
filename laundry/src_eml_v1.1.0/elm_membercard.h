#ifndef __ELM_MEMBERCARD_H__
#define __ELM_MEMBERCARD_H__

#include <glib.h>

#include <sys/types.h>
#include <time.h>
#include <termios.h>

unsigned long long membercard[1000][3];
int indeks;

gboolean get_card_member_data (const char *);
gboolean find_card_member_uid (unsigned long long );
gboolean card_member_update (unsigned long long *uid, unsigned long long *saldo);
gboolean card_member_insert_file (int);
gboolean get_card_member_data_file ();
gboolean card_member_update_file (unsigned long long *uid, unsigned long long *saldo);



#endif /* __ELM_MEMBERCARD_H__ */

