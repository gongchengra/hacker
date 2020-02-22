all:402 403 407 410 411 412 413 417 419 421
402:
	gcc eg.04.02.postfix-expression-evaluation.c eg.04.04.array-implementation-of-stack.c -o eg.04.02.postfix-expression-evaluation.exe
	./eg.04.02.postfix-expression-evaluation.exe '50 9 8 + 4 6 * * 7 + *'
403:
	gcc eg.04.03.infix-to-postfix-conversion.c eg.04.05.linked-list-implementation-of-stack.c -o eg.04.03.infix-to-postfix-conversion.exe
	./eg.04.03.infix-to-postfix-conversion.exe '(5 * ( ( ( 9 + 8 ) * ( 4 * 6 ) ) + 7 ))'
	echo 'wrong result without the outmost ()'
	./eg.04.03.infix-to-postfix-conversion.exe '5 * 8'
407:
	gcc eg.04.07.equivalence-relations-adt-client.c eg.04.08.equivalence-relations-adt-implementation.c -o eg.04.07.equivalence-relations-adt-client.exe
	./eg.04.07.equivalence-relations-adt-client.exe 10
410:
	gcc eg.04.10.fifo-queue-adt-client.c eg.04.10.fifo-queue-linked-list-implementation.c -o eg.04.10.fifo-queue-adt-client.exe
	./eg.04.10.fifo-queue-adt-client.exe
411:
	gcc eg.04.10.fifo-queue-adt-client.c eg.04.11.fifo-queue-array-implementation.c -o eg.04.11.fifo-queue-adt-client.exe
	./eg.04.11.fifo-queue-adt-client.exe
412:
	gcc eg.04.12.client.c eg.04.12.stack-with-index-items-and-no-duplicates.c -o eg.04.12.client.exe
	./eg.04.12.client.exe 5
413:
	gcc eg.04.13.complex-numbers-driver.c eg.04.15.complex-numbers-data-type-implementation.c -o eg.04.13.complex-numbers-driver.exe
	./eg.04.13.complex-numbers-driver.exe 8
417:
	gcc eg.04.17.complex-numbers-driver.c eg.04.17.complex-numbers-adt-implementation.c -o eg.04.17.complex-numbers-driver.exe
	./eg.04.17.complex-numbers-driver.exe 8
419:
	gcc eg.04.19.queue-client.c eg.04.20.linked-list-implementation-of-first-class-queue.c -o eg.04.19.queue-client.exe
	./eg.04.19.queue-client.exe 50
420:
	gcc eg.04.19.queue-client.v1.c -o eg.04.19.queue-client.v1.exe
	./eg.04.19.queue-client.v1.exe 50
421:
	gcc eg.04.21.ploynomial-client.c eg.04.23.array-implementation-of-polynomial-adt.c -o eg.04.21.ploynomial-client.exe
	./eg.04.21.ploynomial-client.exe 5 2
422:
	gcc eg.04.21.ploynomial-client.v1.c -o eg.04.21.ploynomial-client.v1.exe
	./eg.04.21.ploynomial-client.v1.exe 5 2
.PHONY:clean
clean:
	rm *.exe
