/**
 * builder.c - GTK+ UI handler
 *
 * Tool Collecting Terminal
 * Copyright (C) 2008 - 2010 Delameta Bilano,. Ardhan Madras <ajhwb@knac.com>
 */
 
#include <stdlib.h>

#include <stdio.h>
#include <wiringPi.h>
#include "elm.h"


inline int elm_debug (ELMDebug		level, const char *fmt, ...)
{
	g_return_val_if_fail (fmt != NULL, -1);

	int retval = 0;
	time_t st;
	struct tm lt;
	va_list args;
	char *tmp, *time_str;
	static const char * const title[] = 
	{
		"INFO", 
		"WARNING", 
		"ERROR", 
		"FATAL" 
	};

	va_start (args, fmt);
	tmp = g_strdup_vprintf (fmt, args);
	va_end (args);

	st = time (NULL);
	localtime_r (&st, &lt);
	time_str = g_strdup_printf ("%i-%.2i-%.2i_%.2i:%.2i:%.2i", 
								(lt.tm_year + 1900) % 100,
								lt.tm_mon + 1, lt.tm_mday, lt.tm_hour,
								lt.tm_min, lt.tm_sec);

	retval = g_fprintf (stderr, "%s %s: %s", time_str, title[level], tmp);

	g_free (tmp);
	g_free (time_str);

	return retval;
}


char* elm_get_idshift (int	gardu, int	shift,	int	period,time_t cycle)
{
	char *retval;
	struct tm st;

	localtime_r (&cycle, &st);
	retval = g_strdup_printf   ("%.2i%.2i%.2i%.2i%i%.2i", 
								gardu, st.tm_mday, st.tm_mon + 1,
								(st.tm_year + 1900) % 100, shift, period);
	return retval;
}

int optocoupler_on()
{
	digitalWrite (1, 1) ;
	
	return 1;
	
}

int optocoupler()
{
	digitalWrite (1, 0) ;     // Off
    delay (50) ;               // mS
    digitalWrite (1, 1) ;     // Oo
	
	return 1; 
	
}

