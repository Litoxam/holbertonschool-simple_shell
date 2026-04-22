#include "main.h"

/**
 * handle_env - display all environment variables when `env` is called
 * @args: pointer of array of string - use to handle args for exit cmd
 * @prog: string - name of our program (not used here)
 * @line_number: - number of the actual line (not used here)
 * Return: int - (0) on success
 */

int handle_env(char **args, char *prog, int line_number)
{
	int i;
	(void)prog;
	(void)line_number;

	i = 0;
	(void)args;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
