#include <stdio.h>
#include "mult.h"

//uan
int main() {
  int num_rows = 5, num_cols = 8;
  int** mult_table = make_mult_table(num_rows, num_cols);
  print_table(mult_table,num_rows, num_cols);

  printf("\n\n");

  add_row(&mult_table, &num_rows, num_cols);
  print_table(mult_table,num_rows, num_cols);

	fill_table(mult_table, num_rows, num_cols, 37);
	print_table(mult_table,num_rows, num_cols);

  delete_table(&mult_table, num_rows, num_cols);
  return 0;
}
