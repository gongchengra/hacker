ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = 07.01.hello1 07.03.doatexit 07.04.echoarg 07.13.testjmp 07.16.getrlimit

all:	$(PROGS) 07.14.opendata.o scope.o

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.exe

include $(ROOT)/Make.libapue.inc
