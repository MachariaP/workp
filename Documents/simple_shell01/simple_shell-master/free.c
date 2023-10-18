#include "main.h"

/**
 * free_args_by_index - frees argument array by index
 * @args: array of arguments passed
 * @count: argument count
 *
 * Return: void
 */
void free_args_by_index(char **args, int count)
{
	while (count >= 0)
	{
		free(args[count]);
		count--;
	}

	free(args);
}

/**
 * free_args - frees argument array
 * @args: array of arguments passed
 *
 * Return: void
 */
void free_args(char **args)
{
	free(*args);
	free(args);
}

/**
 * __exit - exit process
 * @args: array of arguments passed
 * @tmp: input string
 * @tokens: array of string
 *
 * Return: void
 */
void __exit(char **args, char *tmp, char **tokens)
{
	free_args(args);
	free_args(tokens);
	free(tmp);
	exit(0);
}
