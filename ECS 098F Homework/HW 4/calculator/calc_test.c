/*
 * Program to test the calculator program 
 */
#include <stdio.h>
#include <stdbool.h>

#include "calc.h"

#define NUM_TESTS 26

struct pair{
  char* equation;
  int value_of_the_equation;
};

struct pair input_output_pairs[NUM_TESTS] = {
  {.equation = "2 + 2", .value_of_the_equation = 4},
  {.equation = "2 - 2", .value_of_the_equation = 0}, 
  {.equation = "2 * 2", .value_of_the_equation = 4},
  {.equation = "2 / 2", .value_of_the_equation = 1},
  {.equation = "(2 + 2) * 4", .value_of_the_equation = 16},
  {.equation = "3 / 2", .value_of_the_equation = 1},
  {.equation = "(0 - 3) / 2", .value_of_the_equation = -1},
  {.equation = "(7 * 4) / 2", .value_of_the_equation = 14},
  {.equation = "2 / 5 - 7", .value_of_the_equation = -7},
  {.equation = "(3 - 4) * 2", .value_of_the_equation = -2},
  {.equation = "5 - (5 + 2) * 3 / 2", .value_of_the_equation = -5},
  {.equation = "9 - 5 + 2 * 3 / 2", .value_of_the_equation = 7},
  {.equation = "(-3) + 2", .value_of_the_equation = -1},
  {.equation = "-3 + 5", .value_of_the_equation = 2},
  {.equation = "-3/2", .value_of_the_equation = -1},
  {.equation = "-1 - 1", .value_of_the_equation = -2},
  {.equation = "3 - 2 * 8 * 9 - 6 + 7", .value_of_the_equation = -140},
  {.equation = "1 * 0", .value_of_the_equation = 0},
  {.equation = "0 * 0", .value_of_the_equation = 0},
  {.equation = "0 - 1", .value_of_the_equation = -1},
  {.equation = "1 - 0", .value_of_the_equation = 1},
  {.equation = "(2 - 3) / (3 - 7)", .value_of_the_equation = 0},
  {.equation = "(2)(4)", .value_of_the_equation = 8},
  {.equation = "(2)(0)", .value_of_the_equation = 0},
  {.equation = "0 * 2 / 1", .value_of_the_equation = 0},
  {.equation = "1234567891234567 / 6758934", .value_of_the_equation = 182657189},
};

// Given the index of an input-output pair, run the test on the username
// validator. Returns true if the tests passes, false otherwise.
bool run_test(int test_num) {
  char *input = input_output_pairs[test_num].equation;
  int real_output = calc(input);
  int expected_output = input_output_pairs[test_num].value_of_the_equation;
  if (real_output != expected_output) {
    printf("Test %d failed! Expected %s to %sbe a valid input\n", test_num,
        input, expected_output ? "" : "not ");
    return false;
  }
  return true;
}

int main(int argc, char **argv) {
  int num_passed = 0;
  for(int i = 0; i < NUM_TESTS; i++) {
    if(run_test(i))
      num_passed++;
  }
  printf("%i out of %i tests passed.\n", num_passed, NUM_TESTS);
}
