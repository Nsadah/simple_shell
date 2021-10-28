#include "header.h"
/**
 * main - simple shell function.
 * @ac: arguments count.
 * @av: arguments vector.
 * @envp: enviroments variables.
 * Return: int.
 */

int main(int ac, char **av, char **envp)
{
	char *lineptr = NULL, **cmds, *fp_res;
	size_t s = 0;
	int status = 0, cmd_n = 0;
	ssize_t n_chars;

	(void)ac;
	(void)envp;
	signal(SIGINT, sig_handler);
	if (isatty(STDIN_FILENO))
		_pstr("$ ");
	while ((n_chars = getline(&lineptr, &s, stdin)) != -1)
	{
		cmds = NULL;
		if (lineptr)
			cmds = create_cmds(lineptr);
		cmd_n++;
		if (!cmds || !cmds[0])
			;
		else
		{
			if (_strcmp(cmds[0], "exit") == 0)
			{
				_free_proc_conds(cmds, lineptr), exit_func(cmds);
			}
			fp_res = _find_path(*cmds);
			if (fp_res != NULL)
				cmds[0]  = _strdup(fp_res);
			exec_usr_input(av[0], cmds, status, lineptr);
		}
		if (isatty(STDIN_FILENO))
			_pstr("$ ");
	}
	if (n_chars == -1)
	{
		if (isatty(STDIN_FILENO))
			_putchar('\n');
		exit(0);
	}
	_free_proc_conds(cmds, lineptr);
	return (0);
}
