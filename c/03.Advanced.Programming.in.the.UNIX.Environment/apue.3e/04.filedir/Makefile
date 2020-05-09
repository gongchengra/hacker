ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

ifeq "$(PLATFORM)" "linux"
	ZAP = 04.21.zap
else
	ZAP =
endif

PROGS =	04.03.filetype 04.08.access 04.09.umask 04.12.changemod 04.16.unlink \
		04.23.mycd 04.24.cdpwd 04.25.devrdev $(ZAP)
MOREPROGS = 04.22.ftw8

all:	$(PROGS) $(MOREPROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

ftw8:	ftw8.c $(LIBAPUE)
	$(CC) $(CFLAGS) $(NAMEMAX) ftw8.c -o ftw8 $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(MOREPROGS) $(TEMPFILES) *.o $(ZAP) *.exe

include $(ROOT)/Make.libapue.inc
