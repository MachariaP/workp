#include "main.h"

/**
 * find_executable - find path from $PATH directories
 * @input: input string
 * @path: current $PATH env
 *
 * Return: pointer to a new allocated string or NULL
 */
char *find_executable(char *path, char *input)
{
	size_t dest_len;
	char *dest, *result = NULL, *s1;
	struct stat sb;

	s1 = strtok(path, ":");
	while (s1 != NULL)
	{
		dest_len = _strlen(s1) + _strlen(input) + 2;
		dest = (char *)malloc(dest_len);
		if (dest == NULL)
		{
			free(result);
			return (NULL);
		}
		_strcpy(dest, s1);
		if (dest[_strlen(dest) - 1] != '/')
			_strcat(dest, "/");

		_strcat(dest, input);
		if (stat(dest, &sb) != -1)
		{
			char *temp = (char *)malloc(sizeof(char) * _strlen(dest) + 1);

			if (temp == NULL)
			{
				free(result);
				free(dest);
				return (NULL);
			}
			_strcpy(temp, dest);
			free(result);
			result = temp;
		}
		free(dest);
		s1 = strtok(NULL, ":");
	}
	return (result);
}

/**
 * get_path_from_environ - gets path from global env
 * @path: path to the global env variable
 * @s: input string
 *
 * Return: pointer to path
 */
char *get_path_from_environ(const char *path, const char *s)
{
	char *copy_of_s;
	char *p;
	char *result;

	if (path == NULL || path[0] == '\0')
	{
		return (NULL);
	}

	p = custom_strdup(path);
	copy_of_s = custom_strdup(s);
	result = find_executable(p, copy_of_s);

	free(p);
	free(copy_of_s);

	return (result);
}
