mult_table.out: main.o mult.o
	gcc -g -Wall -Werror -o mult_table.out main.o mult.o

main.o: main.c mult.h
	gcc -g -Wall -Werror -c main.c

mult.o: mult.c mult.h
	gcc -g -Wall -Werror -c mult.c

clean:
	rm -f *.o *.out
