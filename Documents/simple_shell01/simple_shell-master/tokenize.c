#include "main.h"

/**
 * count_token - tokenizes an input string
 * @input: input string
 *
 * Return: number of tokens
 */
int count_token(char *input)
{
	char *copy;
	char *s;
	int n = 0;
	char *delimeter;

	copy = custom_strdup(input);
	delimeter = custom_strdup(" \n\t\r");
	s = strtok(copy, delimeter);

	while (s)
	{
		n++;
		s = strtok(NULL, delimeter);
	}

	free(copy);
	free(delimeter);
	return (n);
}
