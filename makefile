CC=gcc
AR=ar
FLAGS= -Wall -g

all: main

main: main.o libmyBank.a
	$(CC) $(FLAGS) -o main main.o -L. -lmyBank

libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a myBank.o

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

main.o: main.c
	$(CC) $(FLAGS) -c main.c

.PHONY: clean
clean:
	rm -f main *.o *.a