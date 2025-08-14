# Makefile for HW2, ecs36b, s2023
#

CC = gcc
# CC = g++ -std=c++14
CFLAGS = -g -Wall -Wstrict-prototypes

# rules.
all: wordle_ecs36b_s2023

#
#
wordle_ecs36b_s2023.o:	wordle_ecs36b_s2023.c
			$(CC) -c $(CFLAGS) wordle_ecs36b_s2023.c

wordle_ecs36b_s2023:	wordle_ecs36b_s2023.o
			$(CC) -o wordle_ecs36b_s2023 wordle_ecs36b_s2023.o

clean:
	rm -f *.o *~ core wordle_ecs36b_s2023 wordle_orig
