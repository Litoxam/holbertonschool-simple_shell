#include <stdio.h>
#include <stddef.h>
#include "main.h"


/**
 * main - entry point
 * @argc: int - number of arguments, set to (void)
 * @argv: pointer of array of char - array of args written in stdin
 *
 * Return: 0 if success
 */



int main(int argc, char **argv)
{

	(void)argc;
	char *line = NULL;
	char **args;
	size_t n = 0;
	ssize_t user_input;
	int checker;

	printf("<3 ");

	while (user_input = getline(&line, &n, stdin) != -1)
	{

		printf("<3 ");
		args = parsing_user_input(line);
		checker = check_if_command_exists(*args)
		if (checker == 0)
			//exec function
		else
			{
				printf("Command doesn't exist")
				break;
			}

	}
	free(line);
	free(args)
	return (0);

}
