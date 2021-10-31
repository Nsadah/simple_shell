#include "simple_shell.h"
#include <errno.h>

/**
 *start_shell - Simple shell
 *@name: name of the executable
 *Return: 0
 */

void start_shell(char *name)
{
	ssize_t numLines = 0;
	size_t len = 0;
	int lenPrompt = 0, wstatus = 0, wstatus_tmp = 15, line = 0;
	char *buffer = NULL, **argv;
	pid_t child_pid;

	check_interactive(&lenPrompt);
	print_prompt(lenPrompt);
	while ((numLines = _getline(&buffer, &len, stdin)) != -1)
	{
		line++;
		wstatus_tmp = wstatus;
		argv = split(buffer, " \t\n");
		check_exit(argv);
		child_pid = fork();
		child_pid == -1 ? perror(name) : (void) 0;
		if (child_pid == 0)
			if (argv != NULL)
				valid_command(argv, name, line);
			else
			{
				free(buffer);
				exit(EXIT_FAILURE);
			}
		else
		{
			wait(&wstatus);
			hand_status(&wstatus, argv, name, buffer, wstatus_tmp);
		}
		print_prompt(lenPrompt);
		free(buffer);
		free(argv);
		buffer = NULL;
	}
}

/**
 *hand status - handling exit status
 *@wstatus: pointer to the value to be printed in terminal as prompt
 *@argv: data arrays with commands
 *@name: name
 *@buffer: buffer
 *@wstatus_tmp: temporal wstatus
 *Return: none
 */
void hand_status(int *wstatus, char **argv, char *name, char *buffer, int wstatus_tmp)
{
	if (WIFEXITED(*wstatus) == 1)
	{
		*wstatus = WEXITSTATUS(*wstatus) & 0xFF;
		if (*wstatus != 0 &&  *wstatus != 1 &&
		    *wstatus != 255 && *wstatus != 127)
		{
			if (*wstatus == 123)
				cd_parent(argv, name);
			else
			{
				free(buffer);
				free(argv);
				if (*wstatus == 124)
					exit(wstatus_tmp);
				else
					exit(*wstatus);
			}
		}
		if (*wstatus == 127 && isatty(STDIN_FILENO) == 0)
			exit(127);
	}
}

/**
 *print_prompt- print the prompt in shell
 *@lenPrompt: len of prompt
 *Return: none
 */

void print_prompt(int lenPrompt)
{
	char *cp, *my_prompt, *buf = NULL;
	char *prompt = "\033[1m\x1B[34mShelley\x1B[0m:";
	int len;

	if (lenPrompt != 0)
	{
		cp = getcwd(buf, 0);
		my_prompt = str_concat(prompt, cp);
		len = _strlen(my_prompt);
		write(STDOUT_FILENO, my_prompt, len);
		write(STDOUT_FILENO, "$ ", 2);
		free(cp);
		free(my_prompt);
	}
}

/**
 *check_interactive - checks if the shell is interactive or not
 *@lenPrompt: pointer to the value to be printed in terminal as prompt
 *Return: none
 */

void check_interactive(int *lenPrompt)
{
	if (isatty(STDIN_FILENO) == 0)
	{
		*lenPrompt = 0;
	}
}

/**
 *check_exit - checks if exit command
 *@argv: arguments
 *Return: none
 */
void check_exit(char **argv)
{
	int num;

	if (argv == NULL)
		return;
	if (_strncmp(argv[0], "exit", 0) == 0 && argv[1] != NULL)
	{
		num = _atoi(argv[1]);
		if (num == 127 || (num >= 0 || num <= 1) || num == 255)
			exit(num);
	}
}
