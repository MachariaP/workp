#include "main.h"

/**
 * _strcat - concatenates two strings
 *
 * @dest: copy destination
 * @src: copy source
 *
 * Return: pointer to dest.
 */
char *_strcat(char *dest, const char *src)
{
	int i = 0;
	int len = 0;

	while (dest[i++])
	{
		len++;
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len + i] = src[i];
	}

	dest[len + i] = '\0';

	return (dest);
}

/**
 * _strncpy - copies a string
 *
 * @dest: copy destination
 * @src: copy source
 * @n: bytes from @src
 *
 * Return: pointer to dest.
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int index = 0, src_len = 0;

	while (src[index++])
		src_len++;

	for (index = 0; src[index] && index < n; index++)
		dest[index] = src[index];

	for (index = src_len; index < n; index++)
		dest[index] = '\0';

	return (dest);
}
