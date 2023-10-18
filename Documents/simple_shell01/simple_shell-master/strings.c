#include "main.h"

/**
 * _strlen - a function that gets a length of a tring
 *
 * @str: sting to get length
 *
 * Return: length of string
 */
int _strlen(const char *str)
{
	int length = 0;

	if (str == NULL)
		return (0);

	while (*str++)
		length++;

	return (length);
}

/**
 * _print - prints characters to the standard output
 * @str: input string
 *
 * Return: void
 */
void _print(const char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

/**
 * _strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 *
 * @dest: copy destination
 * @src: copy source
 *
 * Return: the pointer to dest.
 */

char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: int.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * custom_strdup - duplicates a string
 * @str: input string
 *
 * Return: pointer to a new allocated string
 */
char *custom_strdup(const char *str)
{
	char *duplicate = NULL;
	size_t len;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str);
	duplicate = (char *)malloc(len + 1);
	if (duplicate == NULL)
	{
		return (NULL);
	}

	_strcpy(duplicate, str);
	return (duplicate);
}
