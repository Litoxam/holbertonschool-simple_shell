#include "main.h"

/**
 * check_builtins - checks if cmd passed by the user is a builtins functions
 * and roots to the associated function
 * @args: pointer to array of string - args passed to our shell
 * Return: int - (0) if success through the pointed function -
 * (-1) if don't match
 */
int check_builtins(char **args)
{
	int i;


	builtin_t array_of_builtins[] = {
		{"exit", handle_exit},
		{"env", handle_env},
		{NULL, NULL}
	};

	i = 0;
	while (array_of_builtins[i].name != NULL && array_of_builtins[i].f != NULL)
	{
		if (strcmp(array_of_builtins[i].name, args[0]) == 0)
			return (array_of_builtins[i].f(args));
		i++;
	}

	return (-1);
}
