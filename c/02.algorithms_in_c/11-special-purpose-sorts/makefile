all: 1102 1103 1104
1102:
	gcc eg.11.02.batchers-odd-even-merge.c -o eg.11.02.batchers-odd-even-merge.exe
#     We shall implicitly assume in the text throughout this section and
#     Section 11.2 that the number of items to be sorted is a power of 2.
	./eg.11.02.batchers-odd-even-merge.exe 4
1103:
	gcc eg.11.03.batchers-odd-even-merge-bottomup.c -o eg.11.03.batchers-odd-even-merge-bottomup.exe
	./eg.11.03.batchers-odd-even-merge-bottomup.exe 8
1104:
	gcc eg.11.04.batchers-odd-even-sort-nonrecursive.c -o eg.11.04.batchers-odd-even-sort-nonrecursive.exe
	./eg.11.04.batchers-odd-even-sort-nonrecursive.exe 12
.PHONY: clean
clean:
	rm *.exe *.log
