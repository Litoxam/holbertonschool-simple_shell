#include "main.h"


/**
 * check_if_command_exists - use the stat func to check if cmd exists
 * @arg: string - tokens[0] in the main function
 *
 * Return: int - 0 if it exists - 1 if it doesn't
 */

int check_if_command_exists(char *arg)
{
	struct stat st;

	if (stat(arg, &st) == 0)
		return (0);
	else
		return (1);

}
