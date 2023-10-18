#include "main.h"

/**
 * catch_ctrlc - catch ctrl + C signal
 * @sig: signal value
 *
 * Return: void
 */
void catch_ctrlc(__attribute__((__unused__)) int sig)
{
	signal(SIGINT, catch_ctrlc);
	_print("\n$ ");
}

/**
 * execute_normal_mode - interactive mode
 * @av: argument vector
 *
 * Return: exit status (int)
 */
int execute_normal_mode(char *av)
{
	int flag = 0;
	size_t len = 0;
	int byteRead = 0;
	char *input = NULL;

	_print("$ ");
	byteRead = getline(&input, &len, stdin);
	if (byteRead == -1)
	{
		free(input);
		_print("\n");
		return (-1);
	}

	if (input[0] == '\0' || input[1] == '\0')
		flag = 1;

	if (flag == 0)
	{
		flag = execute(input, byteRead, NULL);
		if (flag > 0)
		{
			show_errors(flag, av, input, 2);
			free(input);
			return (flag);
		}
		free(input);
	}

	return (flag);
}

/**
 * main - check code
 * @ac: argument count
 * @av: argument vector
 *
 * Return: int
 */
int main(__attribute__((__unused__)) int ac, char **av)
{
	int res = 0;

	if (!isatty(STDIN_FILENO))
	{
		res = execute_pipe_mode(STDIN_FILENO, av[0]);
	}
	else
	{
		signal(SIGINT, catch_ctrlc);
		while (1)
		{
			res = execute_normal_mode(av[0]);
			if (res == -1)
				break;
		}
	}

	return (res);
}
