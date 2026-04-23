#include "main.h"

/**
 * is_numeric - checks if a char is a digit
 * @str: pointer to string - string to check
 * @prog: string - name of our prog (not used here)
 *
 * Return: (1) if string contains only digit - (0) if not
 */

int is_numeric(char *str, char *prog)
{
	int i;
	(void)prog;

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
 * @prog: string - name of our program
 * @line_number: int - number of the actual ligne
 * Return: int
 */

int handle_exit(char **args, char *prog, int line_number)
{
	if (!args[1])
	{
		return (-2);
	}

	if (is_numeric(args[1], prog) == 0)
	{
		fprintf(stderr, "%s: %d: exit: Illegal number: %s\n",
			prog, line_number, args[1]);
		return (2);
	}

	return (-2);
}
