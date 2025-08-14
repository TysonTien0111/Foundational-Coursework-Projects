% 1. It has been optimized for readability, understandability, and
% maintainability.
% 2. It follows proper, modern, and professional Prolog conventions.
% 3. It is clean, safe, and effective code.
% 4. And it follows the philosophy of open to extensibility but closed off to
% modifications.
% 5. It is efficient in terms of implementation for the underlying low level
% hardware.
% 6. Lastly, any other rules, aka modern industry standards or anything that I
% didn't include above, that I need to follow, since the above rules aren't
% exhaustive.

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
/* Name: Tyson-Tien Nguyen */
/* Student Number: 921031514 */

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
% Need To Prove That Each Row, Col, And 3x3 Are Valid.
sudoku(L) :- validRows(L), validCols(L), valid3x3(L).

% YOU NEED TO COMPLETE THIS PREDICATE, PLUS PROVIDE ANY HELPER PREDICATES BELOW.

% Valid If Row Is Empty.
validRows([]).
% Valid If Current Row Is Valid And Rest Of Rows Are Valid As Well.
validRows([CurrentRow | RestOfRows]) :- validValuesInRow(CurrentRow),
validRows(RestOfRows).

% The Row is Valid If The Current Row Has Values From Only 1 Through 9 And Each.
% Value Is Unique, Aka, Only Showing Up Once.
validValuesInRow(CurrentRow) :- permutation(CurrentRow, [1, 2, 3, 4, 5, 6, 7, 8,
9]).

% Valid If Col Is Empty.
validCols([]).
% Valid If The Transposed Cols Are Valid Rows.
validCols(SudokuGrid) :- transpose(SudokuGrid, TransposedCols),
validRows(TransposedCols).

% Valid If 3x3 Is Empty.
valid3x3([]).
% Valid If ListOfBlocks Are Valid Rows.
valid3x3(SudokuGrid) :- sudokuBlocks(SudokuGrid, ListOfBlocks),
validRows(ListOfBlocks).

% Transpose Of Empty List Is Just An Empty List.
transpose([], []).
transpose([[] | _], []).
% Swap Columns To Rows And Rows To Columns.
transpose(SudokuGrid, [CurrentCol | RestOfCols]) :- firstElemOfRows(SudokuGrid,
CurrentCol), remainingElementsOfRows(SudokuGrid, GridOfTails),
transpose(GridOfTails, RestOfCols).

% Transpose Of Empty Col Is Just Empty Row.
firstElemOfRows([], []).
% Swap The Cols And The Rows For One Col.
firstElemOfRows([[HeadOfRow | _] | RestOfRows], [HeadOfRow | RestOfCols]) :-
firstElemOfRows(RestOfRows, RestOfCols).

% Transpose Of The Remaining Empty Cols Is Just The Remaining Empty Rows.
remainingElementsOfRows([], []).
% Swap The Cols And The Rows For The Remaining Cols.
remainingElementsOfRows([[_ | TailOfRow] | RestOfRows], [TailOfRow |
RestOfTails]) :- remainingElementsOfRows(RestOfRows, RestOfTails).

% empty grid produces empty grid
sudokuBlocks([], []).
% convert sudoku 3x3 blocks into lists of blocks.
sudokuBlocks([RowOne, RowTwo, RowThree | RestOfRows], [BlockOne, BlockTwo,
BlockThree | RestOfBlocks]) :- rowsToBlocks([RowOne, RowTwo, RowThree],
[BlockOne, BlockTwo, BlockThree]), sudokuBlocks(RestOfRows, RestOfBlocks).

% Convert Rows To Blocks Via Transposition Method.
rowsToBlocks([RowOne, RowTwo, RowThree], [BlockOne, BlockTwo, BlockThree]) :-
transpose([RowOne, RowTwo, RowThree], TransposedRows),
transposedRowsToBlocks(TransposedRows, [BlockOne, BlockTwo, BlockThree]).

% Empty Transposed Rows To Empty Blocks.
transposedRowsToBlocks([], []).
% Convert Transposed Rows To 3x3 Blocks.
transposedRowsToBlocks([ListOne, ListTwo, ListThree | RestOfTransposedRows],
[SudokuBlock | RestOfBlocks]) :- append(ListOne, ListTwo, TempList),
append(TempList, ListThree, SudokuBlock),
transposedRowsToBlocks(RestOfTransposedRows, RestOfBlocks).
