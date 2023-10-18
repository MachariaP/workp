#include "main.h"

/**
 * execute - executes arguments
 * @input: input string
 * @length: length of the string
 * @tokens: array of string
 *
 * Return: integer
 */
int execute(char *input, int length, char **tokens)
{
	char **args;
	pid_t child_pid;
	int status, flag = 0, i = 0;

	args = parse_input(input, length);
	if (args[0] == NULL)
		flag = 127;
	else if (_strcmp(args[0], "exit") == 0)
		__exit(args, input, tokens);
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error child:");
			return (1);
		}

		if (child_pid == 0)
		{
			execve(args[0], args, environ);
			return (errno);
		}
		else
		{
			waitpid(child_pid, &status, 0);
			flag = WEXITSTATUS(status);
		}
	}

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);

	return (flag);
}
