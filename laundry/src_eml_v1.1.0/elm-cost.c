#include <glib.h>
#include <libpq-fe.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "elm-cost.h"
#include "elm-db.h"
#include "elm-setting.h"
#include "elm.h"



static gboolean elm_cost_write (const char *filename,
																		 const int	*cost)
{
	int fd, ret;
	size_t bytes;

	fd = open (filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		{
			elm_debug (ELM_DEBUG_ERROR, "%s: %s: %s\n", 
								 __func__, filename, g_strerror (errno));
			return FALSE;
		}
	bytes = sizeof(int);

	ret = write (fd, cost, bytes);
	if (ret != bytes)
		{
			elm_debug (ELM_DEBUG_ERROR, "%s: %s\n", __func__, g_strerror (errno));
			close (fd);
			return FALSE;
		}
	close (fd);
	return TRUE;
}

static gboolean elm_cost_update (const char *cmd)
{
	GChecksum *cksum;
	PGconn *conn;
	PGresult *res;
	int status, row, col, i, j;


	if (!elm_db_connect (&conn))
		return FALSE;
	res = PQexec (conn, cmd);
	status = PQresultStatus (res);
	if (status != PGRES_TUPLES_OK)
		{
			elm_debug (ELM_DEBUG_ERROR, "%s: %s", __func__, 
								 PQresultErrorMessage (res));
			elm_db_close (&conn);
			return FALSE;
		}
	row = PQntuples (res);
	col = PQnfields (res);

	if (!(col == 6))
		{
			elm_debug (ELM_DEBUG_WARNING, "%s: invalid row or col number: %s\n", __func__, cmd);
			PQclear (res);
			elm_db_close (&conn);
			return FALSE;
		}

	/* fetch data dari query */
	
			cost[0] = strtol (PQgetvalue (res, 0, 1), NULL, 10);
			cost[1] = strtol (PQgetvalue (res, 0, 2), NULL, 10);
			cost[2] = strtol (PQgetvalue (res, 0, 3), NULL, 10);
			cost[3] = strtol (PQgetvalue (res, 0, 4), NULL, 10);
			cost[4] = strtol (PQgetvalue (res, 0, 5), NULL, 10);
			cost[5] = strtol (PQgetvalue (res, 0, 0), NULL, 10);
			PQclear (res);
	elm_db_close (&conn);
	return TRUE;
}


 gboolean elm_get_cost_update()
{
	
	gboolean retval;

	retval = elm_cost_update ("select * from ebv_tarif()");
	if (retval)
		{
		
			if (!(cost[6]==elm_id_tarif))
			{
				elm_cost.pkt1=cost[0];
				elm_cost.pkt2=cost[1];
				elm_cost.pkt3=cost[2];
				elm_cost.pkt4=cost[3];
				elm_cost.pkt5=cost[4];
				elm_id_tarif=cost[5];
				setting_update_cost();
				elm_debug (ELM_DEBUG_INFO, "%s: cost updated \nPAKET 1 %d\nPAKET 2 %d\nPAKET 3 %d\nPAKET 4 %d\nPAKET 5 %d\n",
							__func__,elm_cost.pkt1,elm_cost.pkt2,elm_cost.pkt3,elm_cost.pkt4,elm_cost.pkt5);
			}else
			{
		}
		}else
		{
				elm_debug (ELM_DEBUG_WARNING, "%s: gagal check cost \n", __func__);
				elm_setting_read_cost();
				elm_debug (ELM_DEBUG_INFO, "%s: cost from file \nPAKET 1 %d\nPAKET 2 %d\nPAKET 3 %d\nPAKET 4 %d\nPAKET 5 %d\n",
							__func__,elm_cost.pkt1,elm_cost.pkt2,elm_cost.pkt3,elm_cost.pkt4,elm_cost.pkt5);
			
		}
	return retval;
}


