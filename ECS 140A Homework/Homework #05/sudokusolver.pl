/* ECS 140A Assignment 4 Summer 2025 */
/* Sudoku Solver */

/* For this assignment you will need to implement your 
own 9x9 Sudoku solver in SWI-Prolog.  Basically you 
have a 9x9 grid, and you must fill in the 
grid so that each row, each column, and each of 9 3x3 
grids all contain the numbers 1 through 9. */

/* You will need to fill in the sudoku predicate below, 
and also supply any helper predicates. You should think 
about what has to be true to make a sudoku table valid 
and work out how to check for each of these conditions. */

/* To test your program we will type "test." into 
SWI-Prolog and study the results. */

/* When grading we will be looking for solutions that 
work correctly and run in less than a minute, 
but we also want to see clearly commented 
code explaining what each predicate is doing. If 
your code does not work but appears to be close to a 
working solution or your comments are along the correct 
lines, then you will receive some credit. If your code is not 
clearly commented showing an understanding of what is 
happening then you will receive considerably fewer points
than you might have otherwise. */

% WHAT YOU NEED TO HAND IN
/* You should use Gradescope to submit a plain text file
named 'sudoku.pl' that contains your sudoku predicate and 
any helper predicates. We should be able to run this by 
using the tests provided. The file should contain your 
name and student number. */

/* Keep in mind that you may not use the Constraint
Logic Programming features supplied by SWI-Prolog. */


/* ----------- cut here ----------- */

/* include name and student number */

/* This runs all the simple tests. If it 
works correctly, you should see three identical 
and completed sudoku tables, and finally the 
word false (as test0c will fail.) */
test :-
	test0, nl,
	test0a, nl,
	test0b, nl,
	test0c.

/* This is a completly solved solution. */
test0 :-
	L = [
             [9,6,3,1,7,4,2,5,8],
             [1,7,8,3,2,5,6,4,9],
             [2,5,4,6,8,9,7,3,1],
             [8,2,1,4,3,7,5,9,6],
             [4,9,6,8,5,2,3,1,7],
             [7,3,5,9,6,1,8,2,4],
             [5,8,9,7,1,3,4,6,2],
             [3,1,7,2,4,6,9,8,5],
             [6,4,2,5,9,8,1,7,3]],
        sudoku(L),
        printsudoku(L).

/* This has a solution (the one in test0) which 
should be found very quickly. */
test0a :-
	L = [
             [9,_,3,1,7,4,2,5,8],
             [_,7,_,3,2,5,6,4,9],
             [2,5,4,6,8,9,7,3,1],
             [8,2,1,4,3,7,5,_,6],
	     [4,9,6,8,5,2,3,1,7],
             [7,3,_,9,6,1,8,2,4],
             [5,8,9,7,1,3,4,6,2],
             [3,1,7,2,4,6,9,8,5],
             [6,4,2,5,9,8,1,7,3]],
        sudoku(L),
        printsudoku(L).

/* This has a solution (the one in test0) and 
may take a few seconds to find. */
test0b :-
	L = [
             [9,_,3,1,7,4,2,5,_],
             [_,7,_,3,2,5,6,4,9],
             [2,5,4,6,_,9,_,3,1],
             [_,2,1,4,3,_,5,_,6],
             [4,9,_,8,_,2,3,1,_],
             [_,3,_,9,6,_,8,2,_],
             [5,8,9,7,1,3,4,6,2],
             [_,1,7,2,_,6,_,8,5],
             [6,4,2,5,9,8,1,7,3]],
        sudoku(L),
        printsudoku(L).

/* This one obviously has no solution (column 2 has 
two nines in it.) and it may take a few seconds 
to deduce this. */
test0c :-
	L = [
             [_,9,3,1,7,4,2,5,8],
             [_,7,_,3,2,5,6,4,9],
             [2,5,4,6,8,9,7,3,1],
             [8,2,1,4,3,7,5,_,6],
	     [4,9,6,8,5,2,3,1,7],
             [7,3,_,9,6,1,8,2,4],
             [5,8,9,7,1,3,4,6,2],
             [3,1,7,2,4,6,9,8,5],
             [6,4,2,5,9,8,1,7,3]],
        sudoku(L),
        printsudoku(L).


% print sudoku table
printsudoku([]).
printsudoku([H|T]) :-
	write(H),nl,
	printsudoku(T).


% Expects a list of lists 9 by 9 grid.
sudoku(L) :-

% YOU NEED TO COMPLETE THIS PREDICATE, PLUS PROVIDE ANY HELPER PREDICATES BELOW.


