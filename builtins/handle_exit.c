#include "main.h"

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

	exit_code = _atoi(args[1]);

	exit(exit_code);

	return (0);
}
