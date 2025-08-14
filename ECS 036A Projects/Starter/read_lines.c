#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "read_lines.h"

int open_file(FILE* fp) {
    /*
    This function opens up the fie and counts the amount of characters that are in it.
    This function is from my own program, wcount.c, and I am reusing it in this program.
    Credit: Me(Tyson-Tien Nguyen)
    @num_of_chars stores the ammount of characters that are in the file that is being opened.
    @returns the number of characters that is in the file.
    */

    int num_of_chars = 0;
    char c;

    fscanf(fp, "%c", &c);
    while(!feof(fp)) {
        ++num_of_chars;
        fscanf(fp, "%c", &c);
    }

    return num_of_chars;
}

void count_num_of_lines_in_file(FILE* fp, char** *lines, int *num_lines, int num_of_chars) {
  /*
  This function counts the number of lines in the file.
  @num_of_lines stores the number of lines in the file.
  @array stores the characters in a temporary array in order to be copied over to another array.
  @new_lines_in_file stores the text of the file.
  @the_lines stores the text of the file in separated lines.
  @char c stores the character of the text file
  @num_of_columns stores the number of characters of each line 
  */

  int num_of_lines = 0;
  char* array = (char*)calloc(num_of_chars + 1, sizeof(char));
  char* new_lines_in_file = (char*)calloc(num_of_chars + 1, sizeof(char));

  fseek(fp, 0, SEEK_SET);
  fscanf(fp, "%c", array);
  while(!feof(fp)) {
    strcat(new_lines_in_file, array);
    fscanf(fp, "%c", array);
  }
  free(array);

  for (int i = 0; i < num_of_chars; ++i) {
    if (new_lines_in_file[i] == '\n') {
      ++num_of_lines; 
    }
  }
  free(new_lines_in_file);

  if ((fp != NULL) && (num_of_lines == 0)) {
    ++num_of_lines;
  }

  if (num_of_chars == 0) {
    num_of_lines = 0;
  }

  char** the_lines = (char**)calloc(num_of_lines, sizeof(char*));

  fseek(fp, 0, SEEK_SET);

  for (int row = 0; row < num_of_lines; ++row) {
    char c;
    int num_of_columns = 0;

    fscanf(fp, "%c", &c);
    while(!feof(fp)) {
      if (c != '\n') {
        ++num_of_columns;
      } else {
        ++num_of_columns;
        break;
      }
      fscanf(fp, "%c", &c);
    }

    the_lines[row] = (char*)calloc(num_of_columns + 1, sizeof(char));
    for (int col = 0; col < num_of_columns; ++col) {
      the_lines[row][col] = '*';
    }

    num_of_columns = 0;
  }

  fseek(fp, 0, SEEK_SET);

  for (int row = 0; row < num_of_lines; ++row) {
    for (int col = 0; col < strlen(the_lines[row]); ++col) {
      fscanf(fp, "%c", &the_lines[row][col]);
    }
  }

  if (fp == NULL) {
    *lines = NULL;
    *num_lines = 0;
  } else {
    *num_lines = num_of_lines;
    *lines = the_lines;
  }
}
   
void read_lines(FILE* fp, char*** lines, int* num_lines) {
  /*
      read all of the lines in fp into lines and set num_lines to be the total number of lines in the file.
      @fp: a file pointer opened in read mode
      @lines: a pointer indicating where the lines should be placed. If there are no lines in a fill, lines will be set to NULL
      @num_lines: a pointer to the number of lines. set to the number of lines contained within lines
      @modifies: lines, num_lines
  */
  int num_of_chars = open_file(fp);
  count_num_of_lines_in_file(fp, lines, num_lines, num_of_chars);
}
