connectn.out: clean_up.o main.o play_game.o setup.o user_input.o
	gcc -Wall -Werror -g -o connectn.out clean_up.o main.o play_game.o setup.o user_input.o
clean_up.o: clean_up.c clean_up.h
	gcc -Wall -Werror -g -c clean_up.c
main.o: main.c user_input.h
	gcc -Wall -Werror -g -c main.c
play_game.o: play_game.c play_game.h
	gcc -Wall -Werror -g -c  play_game.c
setup.o: setup.c setup.h
	gcc -Wall -Werror -g -c setup.c
user_input.o: user_input.c user_input.h
	gcc -Wall -Werror -g -c user_input.c
clean:
	rm -f *.o *.out	