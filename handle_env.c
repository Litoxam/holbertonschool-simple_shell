#include "main.h"

/**
 * handle_env - display all environment variables when `env` is called
 * @args: pointer of array of string - use to handle args for exit cmd
 * Return: int - 0
 */

int handle_env(char **args)
{
	int i;

	i = 0;
	(void)args;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
