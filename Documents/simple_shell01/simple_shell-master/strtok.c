#include "main.h"

/**
 * is_delim - checks for delimiter character
 *
 * @c: character to be checked
 * @delim: string of delimiter characters
 *
 * Return: 1 if delim 0 otherwise
 */
unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - breaks a string to tokens
 * @src: source string to be tokenised
 * @delim: string of delimiter characters
 *
 * Return: tokenised string
 *
 */
char *_strtok(char *src, char *delim)
{
	static char *backup_string;
	char *result;

	if (!src)
	{
		src = backup_string;
	}

	if (!src)
	{
		return (NULL);
	}

	while (is_delim(*src, delim))
	{
		src++;
	}

	if (*src == '\0')
	{
		return (NULL);
	}

	result = src;

	while (*src != '\0')
	{
		if (is_delim(*src, delim))
		{
			*src = '\0';
			backup_string = src + 1;
		}
		src++;
	}

	backup_string = src;

	return (result);
}
