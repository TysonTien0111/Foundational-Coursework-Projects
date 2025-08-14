mat_multiply.out: main.o mat_multiply.o
	gcc -Wall -Werror -g -o mat_multiply.out main.o mat_multiply.o

main.o: main.c mat_multiply.h
	gcc -Wall -Werror -g -c main.c

mat_multiply.o: mat_multiply.c mat_multiply.h
	gcc -Wall -Werror -g -c mat_multiply.c

clean:
	rm -fr *.o *.out