CFLAGS=-Wall -g
obj=ex1.exe ex3.exe ex4.exe ex5.exe ex6.exe ex7.exe
all.exe:$(obj)
%.exe:%.c
	gcc -o $@ $< $(CFLAGS)
.PHONY:clean
clean:
	rm -f *.o
	rm -f *.exe
