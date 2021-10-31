#include "simple_shell.h"

/**
 *main - Entry point
 *@argc: number of arguments
 *@argv: array of strings with the arguments inside
 *@env: environmental variables
 *Return: 0
 */

int main(int argc, char *argv[], char **env)
{
	(void)argc;
	signal(SIGINT, CTRLC);
	create_env(env);
	invoke_shell(argv[0]);
	return (0);
}
void init_file(char *key_buff, int leido)
{
	int fd_log, fd_hist, escrito, historico;
	char *my_path;

	my_path = get_home();
	my_path = str_concat(my_path, "/cmd_log.txt");
	fd_log = open(my_path, O_RDWR | O_TRUNC | O_CREAT, 0660);
	free(my_path);
	my_path = get_home();
	my_path = str_concat(my_path, "/cmd_hist.txt");
	fd_hist = open(my_path, O_RDWR | O_APPEND | O_CREAT, 0660);
	free(my_path);
	escrito = write(fd_log, key_buff, leido);
	if (escrito == -1)
		exit(-1);
	historico = write(fd_hist, key_buff, leido);
	if (historico == -1)
		exit(-1);
	close(fd_hist);
	close(fd_log);
}
