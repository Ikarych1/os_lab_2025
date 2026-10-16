CC=gcc
CFLAGS=-I.

all : first_task second_task run_sequential

first_task : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o first_task find_min_max.o utils.o sequential_min_max.c $(CFLAGS)

second_task : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o second_task utils.o find_min_max.o parallel_min_max.c $(CFLAGS)

run_sequential : run_sequential.c first_task
	$(CC) -o run_sequential run_sequential.c $(CFLAGS)

utils.o : utils.h
	$(CC) -o utils.o -c utils.c $(CFLAGS)

find_min_max.o : utils.h find_min_max.h
	$(CC) -o find_min_max.o -c find_min_max.c $(CFLAGS)

clean :
	rm -f utils.o find_min_max.o first_task second_task run_sequential min_max_*.txt