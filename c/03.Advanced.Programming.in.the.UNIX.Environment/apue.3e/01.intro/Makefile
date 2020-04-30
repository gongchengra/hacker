ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS =	01.03.ls 01.04.mycat 01.05.getcputc 01.06.hello.getpid 01.07.shell1 \
		01.08.testerror 01.09.uidgid 01.10.shell2
all:	$(PROGS)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.exe

include $(ROOT)/Make.libapue.inc
