
CC       =  gcc
SOURCES  =   elm_membercard.c lcd_i2c.c elm-cost.c elm-setting.c enco.c elm.c elm-enco.c elm-log.c elm-db.c elm-utils.c  main.c

OBJS     =  $(SOURCES:.c=.o)
CFLAGS   =  -D_REENTRANT -D_VERSION=\"$(VERS)\" \
			-Wno-deprecated-declarations -Wno-unused-but-set-variable \
			-Wno-format-security -Wno-unused-result \
            -c -O2 -Wall -lwiringPi -fsigned-char -Wno-strict-aliasing -Wpointer-arith\
            -I/usr/include/postgresql `pkg-config --cflags gthread-2.0`
LIBS     =  -Wl,--no-as-needed -lwiringPi -lrt -lpthread -lpq -lsqlite3 `pkg-config --libs gthread-2.0`
BUILDIR  =  ./xelm
TARGET   =  $(BUILDIR)/elm
LINES    =  `wc -l *.[c,h] | grep total | cut -d' ' -f3`
VERS     =  `date +1.%y%m.%d`

$(TARGET): $(OBJS)
	@$(CC) $(LIBS) $(OBJS) -o $(TARGET)
	@echo "  LD   elm"
	@strip -s $(TARGET) -o $(TARGET)
	@printf "\ntct: `stat -c %s $(TARGET)` bytes (stripped) of $(LINES) lines\n"
# @echo "SHA-1 digest: `sha1sum $(TARGET) | cut -d ' ' -f1`"

.c.o:
	@echo "  CC   $<"
	@$(CC) $(CFLAGS) $<

.PHONNY: tool
tool:
	@echo "  CC   tct-tool.c"
	@$(CC) $(CFLAGS) tct-tool.c
	@echo "  LD   tct-tool"
	@$(CC) $(LIBS) tct-tool.o -o $(BUILDIR)/tct-tool

.PHONNY: cgi
cgi:
	@echo "  CC   tct-cgi.c"
	@$(CC) $(CFLAGS) tct-cgi.c
	@echo "  LD   index.cgi"
	@$(CC) $(LIBS) tct-cgi.o tct.o tct-setting.o dbkey.key -o $(BUILDIR)/cgi/index.cgi

clean:
	@rm -f *.o $(TARGET)
