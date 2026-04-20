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

	while (1)
	{
		printf("<3 ");
		user_input = getline(&line, &n, stdin);

		if (user_input == -1)
			break;

		args = parsing_user_input(line);

		if (args == NULL || args[0] == NULL)
			continue; /*if the parsing fails or if input is empty*/

		checker = check_if_command_exists(args[0]);
		if (checker == 0)
			//exec function
		else
		{
			printf("Command doesn't exist\n")
		}
		free(args);
	}
	free(line);
	return (0);

}
