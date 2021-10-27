#ifndef HEADER
#define HEADER
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

extern char **environ;

/**
 * struct dir - struct presenting an environment var,used in some functions.
 * @directory_path: environment variable with the format (name=value);
 * @next: pointer to the next node in a linked list of env variables.
 *
 * Description: this struct is used in some functions to make linked list of
 * nodes, each node represents a variable of the the env variables.
 */
typedef struct dir
{
	char *directory_path;
	struct dir *next;
} dir;

int _setenv(const char *name, const char *value, int overwrite);
char *_getenv(const char *name);
int _unsetenv(const char *name);

int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char *_const_strconcat(const char *s1, const char *s2);
char *_strconcat(char *s1, char *s2);
char *_strdup(char *str);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

int _get_cmds_number(char *str);
void _free_cmds(char **cmds);

int _putchar(char c);
void _pstr(char *str);

char *_find_path(char *str);

void _disp_cnf_err(char *pn, char *err_src, int num);
void _disp_err(char *str);

char **create_cmds(char *str);

void sig_handler(int i);

void exec_usr_input(char *av0, char **cmds, int status, char *lineptr);

void _free_proc_conds(char **cmds, char *lineptr);

int _atoi(char *str);

void exit_func(char **cmds);
#endif
