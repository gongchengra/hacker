ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

ACCT=
ACCTFLAGS=
ifeq "$(PLATFORM)" "linux"
  ACCT=pracct
  ACCTFLAGS = -DHAS_AXSIG -DHAS_ACORE
endif
ifeq "$(PLATFORM)" "macos"
  ACCT=pracct
  ACCTFLAGS = -DHAS_AXSIG -DHAS_ACORE
endif
ifeq "$(PLATFORM)" "solaris"
  ACCT=pracct
  ACCTFLAGS = -DHAS_AC_STAT
endif

PROGS =	08.01.fork1 08.03.vfork1 08.06.wait1 08.08.fork2 08.12.tellwait1 08.13.tellwait2 \
		08.16.exec1 08.17.echoall 08.20.exec2 08.25.pruids 08.28.test1 08.30.nice 08.31.times1
MOREPROGS = 08.23.systest1 08.24.systest3

all:	$(PROGS) $(MOREPROGS) system.o $(ACCT)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

systest1:	system.o systest1.o $(LIBAPUE)
		$(CC) $(CFLAGS) -o systest1 systest1.o system.o $(LDFLAGS) $(LDLIBS)

systest3:	system.o systest3.o $(LIBAPUE)
		$(CC) $(CFLAGS) -o systest3 systest3.o system.o $(LDFLAGS) $(LDLIBS)

pracct:		pracct.c $(LIBAPUE)
		$(CC) $(CFLAGS) $(ACCTFLAGS) -o pracct pracct.c $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(MOREPROGS) $(TEMPFILES) *.o $(ACCT) *.exe

include $(ROOT)/Make.libapue.inc
