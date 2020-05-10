ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

ifeq "$(PLATFORM)" "linux"
  MEMSTR = 05.15.memstr
else
  MEMSTR =
endif

PROGS =	05.04.getcputc 05.05.fgetsfputs 05.11.buf 05.12.tempfiles 05.13.mkstemp getcharbug

all:	$(PROGS) $(MEMSTR)

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o $(MEMSTR) *.exe

include $(ROOT)/Make.libapue.inc
