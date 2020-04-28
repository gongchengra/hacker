DIRS = 01.intro 02.standards 03.fileio 04.filedir 05.stdio 06.datafiles \
	07.environ 08.proc 09.relation 10.signals 11.threads 12.threadctl \
	13.daemons 14.advio 15.ipc1 16.sockets 17.ipc2 18.termios \
	19.pty 20.db 21.printer exercises lib

all:
	for i in $(DIRS); do \
		(cd $$i && echo "making $$i" && $(MAKE) ) || exit 1; \
	done

clean:
	for i in $(DIRS); do \
		(cd $$i && echo "cleaning $$i" && $(MAKE) clean) || exit 1; \
	done
