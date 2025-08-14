#ifndef READ_LINES_H
	#define READ_LINES_H
	#include <stdio.h>
	int open_file(FILE* fp);
	void count_num_of_lines_in_file(FILE* fp, char** *lines, int *num_lines, int num_of_chars);
	void read_lines(FILE* fp, char*** lines, int* num_lines);
#endif
