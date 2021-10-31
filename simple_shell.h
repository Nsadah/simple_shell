#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_

/*Standard Libraries*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

/*Prototypes*/
void start_shell(char *name);
void hand_status(int *wstatus, char **argv, char *name, char *buffer, int wstatus_tmp);
void print_prompt(int lenPrompt;
void check_interactive(int *lenPrompt);
void check_exit(char **argv);
#endif
#ifndef BSIZE
#define BSIZE 10000
#endif
