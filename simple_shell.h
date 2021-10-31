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
char **split(char *str, const char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

void check_interactive(int *lenPrompt);
void invoke_shell(char *name);
void valid_command(char **argv, char *name, int line);
int _strncmp(char *s1, char *s2, int n);
char *_which(char *cmd);
char *str_concat(char *s1, char *s2);
void check_cd(char **path, char **Bcmd, char **cat, char *sw);
void create_env(char **env);
int _strlen(char *s);
int _env(char *argv[]);
void pperror(int line, char *name, char **argv);
void CTRLC(int sign);

/**
 *struct bicmds_t - structure of built in commands
 *@name: name of the built in command
 *@f: array of args
 */

/*Structure for Validation*/
typedef struct bicmds_t
{
	char *name;
	int (*f)(char **argv);
} bicmds;

int is_in_delim(char a, const char *delim);
char *look_first_char(char *str, const char *delim);
char *look_first_delim(char *str, const char *delim);
char *look_last_delim(char *str, const char *delim);
char *_strtok(char *str, const char *delim);
int _atoi(char *s);
void init_file(char *key_buff, int leido);

/*Global Variable*/
extern char **environ;

/* Prototype test */
int prueba(char **cadena);
int built_exit(char **cadena);
int built_cd(char **cadena);
void cd_parent(char **argv, char *name);
void print_prompt(int lenPrompt);
int _strcopy(char *str, char *ptr);
void hand_status(int *wstatus, char **argv, char *name,
		 char *buffer, int wstatus_tmp);
char *get_home(void);
int built_history(char **cadena);
char *get_path(void);
char *_strdup(char *str);
int built_help(char **cadena);
void check_exit(char **argv);
char *get_oldpwd(void);
#endif
#ifndef BSIZE
#define BSIZE 10000
#endif
