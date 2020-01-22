all: 1001 1002 1003 1004
1001:
	gcc eg.10.01.binary-quicksort.c -o eg.10.01.binary-quicksort.exe
	./eg.10.01.binary-quicksort.exe 10 1
1002:
	gcc eg.10.02.msd-radix-sort.c -o eg.10.02.msd-radix-sort.exe
	./eg.10.02.msd-radix-sort.exe 10
1003:
	gcc eg.10.03.three-way-radix-quicksort.c -o eg.10.03.three-way-radix-quicksort.exe
	./eg.10.03.three-way-radix-quicksort.exe 10
1004:
	gcc eg.10.04.lsd-radix-sort.c main.c -o eg.10.04.lsd-radix-sort.exe
	./eg.10.04.lsd-radix-sort.exe 10 1
.PHONY: clean
clean:
	rm *.exe *.log
