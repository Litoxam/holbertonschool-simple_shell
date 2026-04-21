#include "main.h"

/**
 * is_numeric - checks if a char is a digit
 * @str: pointer to string - string to check
 * Return: (1) if string contains only digit - (0) if not
 */

int is_numeric(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/**
 * handle_exit - exit function to quit prog
 * @args: pointer of array of string - use to handle args for exit cmd
 * Return: int
 */

int handle_exit(char **args)
{
	int exit_code;
	
	if (!args[1])
	exit(0);
	
	if (is_numeric(args[1]) == 0)
	{
		/** TODO: Need to handle argv[0] to retrieve the program name */
		fprintf(stderr, "%s: exit: %s: numeric argument required\n", args[0], args[1]);
		return (2);
	}

	exit_code = _atoi(args[1]);

	exit(exit_code);

	return (0);
}
