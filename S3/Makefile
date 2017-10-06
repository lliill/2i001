all: test_csvl

csvl.o : csvl.c
	gcc -Wall -c -o csvl.o csvl.c

test_csvl.o : test_csvl.c csvl.h
	gcc -Wall -c -o test_csvl.o test_csvl.c

test_csvl: test_csvl.o csvl.o
	gcc -Wall -o test_csvl test_csvl.o csvl.o

clean :
	rm -f *.o test_csvl
