all: arguments.o
	gcc arguments.o
arguments.o: arguments.c
	gcc -c arguments.c
run:
	./a.out