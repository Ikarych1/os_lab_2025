CC=gcc
CFLAGS=-I.

all : first_task second_task run_sequential

first_task : utils.o find_min_max.o utils.c find_min_max.c
	$(CC)  find_min_max.o utils.o sequential_min_max.c -o first_task $(CFLAGS)

second_task : utils.o find_min_max.o utils.c find_min_max.c
	$(CC)  utils.o find_min_max.o parallel_min_max.c -o second_task $(CFLAGS)

run_sequential : run_sequential.c first_task
	$(CC) -o run_sequential run_sequential.c $(CFLAGS)

utils.o : utils.c
	$(CC)  -c utils.c -o utils.o $(CFLAGS)

find_min_max.o : utils.c find_min_max.c
	$(CC)  -c find_min_max.c -o find_min_max.o $(CFLAGS)

clean :
	rm -f utils.o find_min_max.o first_task second_task run_sequential min_max_*.txt