//
// Created by mfbut on 11/6/2017.
//
#include <stdlib.h>
#include <stdio.h>
#include "mult.h"

//

int** make_mult_table(const int num_rows, const int num_cols) {
  int** table = (int**) malloc(num_rows * sizeof(int*));

  for (int row = 0; row < num_rows; ++row) {
    table[row] = (int*) malloc(num_cols * sizeof(int));
		//table[row] == *(table + row)
    for (int col = 0; col < num_cols; ++col) {
      table[row][col] = (row + 1) * (col + 1);
    }// *(*(table + row) + col)
  }
  return table;
}

void make_mult_table_no_return(const int num_rows, const int num_cols, int*** table) {
 *table = (int**) malloc(num_rows * sizeof(int*));

  for (int row = 0; row < num_rows; ++row) {
    (*table)[row] = (int*) malloc(num_cols * sizeof(int));
		//table[row] == *(table + row)
    for (int col = 0; col < num_cols; ++col) {
      table[0][row][col] = (row + 1) * (col + 1);
      //*(*(*(table + 0) +row) + col)
    }// *(*(table + row) + col)
  }
}


/**
 * Delete a 2D array and set t
 * @param mat
 * @param num_rows
 * @param num_cols
 */
void delete_table(int*** mat, const int num_rows, const int num_cols) {
  for (int row = 0; row < num_rows; ++row) {
    free((*mat)[row]);
  }
  free(*mat);
  *mat = NULL;
}

void fill_array(int* ar, int len, int val){
  for(int i = 0; i < len; ++i){
    ar[i] = val;
  }
}

void fill_table(int** table, int num_rows, int num_cols, int val){
	for(int i =0; i < num_rows; ++ i){
		// for(int j = 0; j < num_cols; ++j){
		// 	table[i][j] = val;
		// }
    fill_array(table[i], num_cols, val);
	}
  table = NULL;
}




/**
 * Print out a 2D array
 * @param mat
 * @param num_rows
 * @param num_cols
 */
void print_table(int** mat, const int num_rows, const int num_cols) {

  for (int row = 0; row < num_rows; ++row) {
    for (int col = 0; col < num_cols; ++col) {
      printf("%3d ", mat[row][col]);
    }
    printf("\n");
  }
}

/**
 * Add a new row to our multiplication table
 * @param mat
 * @param num_rows
 * @param num_cols
 * @return
 */
int** add_row(int*** mat, int* num_rows, const int num_cols) {
  // make space for the row pointer
  *mat = (int**) realloc(*mat, (*num_rows + 1) * sizeof(int*));
  // make space for the elements in the new row
  (*mat)[*num_rows] = (int*) malloc(num_cols * sizeof(int));

  (*num_rows)++; // one more row

  // fill in the elements
  for (int col = 0; col < num_cols; ++col) {
    (*mat)[*num_rows - 1][col] = (*num_rows) * (col + 1);
  }

  return *mat;
}
