#ifndef HEADER_FILE_H
#define HEADER_FILE_H
#include <stdio.h>
#include <stdlib.h>
/**
*Description: This is the header file for the project work
*/

int _isupper(int c);
int cmd_read(char *s, size_t __attribute__((unused))file_stream);
void print_not_found(char *cmd);
int call_command(char *cmd_arr[]);

#endif /* HEADER_FILE_H */
