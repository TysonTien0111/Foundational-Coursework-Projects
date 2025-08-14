#include <stdio.h>

/*
This program will display the Pascal Triangle's levels depending on the number of levels
that the user would like to see.
*/

void fill_in_pascal_triangle(int levels_of_pascal_triangle, int pascal_triangle[levels_of_pascal_triangle][levels_of_pascal_triangle]) {
    /*
    This function fills in the pascal triangle rows.
    @row keeps track of which row we are on.
    @col keeps track of which column we are on.
    */

    int row = 0;
    int col = 0;

    pascal_triangle[row][col] = 1;

    if (levels_of_pascal_triangle >= 2) {
        for (row = 1; row < levels_of_pascal_triangle; ++row) {
            for (; col <= row; ++col) {
                if ((row == col) || (col == 0)) {
                    pascal_triangle[row][col] = 1;
                } else {
                    pascal_triangle[row][col] = pascal_triangle[row - 1][col - 1] + pascal_triangle[row - 1][col];
                }
            }
            col = 0;
        }
    }
}

void display_pascal_triangle(int levels_of_pascal_triangle) {
    /*
    This function will print onto the screen the pascal triangle for the user to 
    see.
    @row tracks the row we are currently in.
    @col tracks the column we are currently in.
    @pascal_triangle[][] stores the actual pascal triangle in the array.
    */

    int row;
    int col;
    int pascal_triangle[levels_of_pascal_triangle][levels_of_pascal_triangle];
    fill_in_pascal_triangle(levels_of_pascal_triangle, pascal_triangle);

    for (row = 0; row < levels_of_pascal_triangle; ++row) {
        for (col = 0; col <= row; ++col) {
            printf("%d ", pascal_triangle[row][col]);
        }
        printf("\n");
    }
}

int main() {
    /*
    This is the main function of the program.
    @levels_of_pascal_triangle stores the number of rows that are in the pascal triangle
    @pascal_triangle[][] is the array that will store the actual pascal triangle 
    */

    int levels_of_pascal_triangle;
    //int pascal_triangle[levels_of_pascal_triangle][levels_of_pascal_triangle];

    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf(" %d", &levels_of_pascal_triangle);

    display_pascal_triangle(levels_of_pascal_triangle);

    return 0;
}