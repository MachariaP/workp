#include "main.h"

/**
 * _get_env - gets environment variable
 * @name: name of variable
 *
 * Return: NULL
 */
char *_get_env(const char *name)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		char *env_var = custom_strdup(environ[i]);
		char *env_name = strtok(env_var, "=");
		char *env_value = strtok(NULL, "=");

		if (env_name != NULL && env_value != NULL && _strcmp(env_name, name) == 0)
		{
			char *result = (char *)malloc(_strlen(env_value) + 1);

			if (result != NULL)
			{
				_strcpy(result, env_value);
				free(env_var);
				return (result);
			}
			else
			{
				free(result);
				free(env_var);
				return (NULL);
			}
		}

		free(env_var);
	}

	return (NULL);
}
