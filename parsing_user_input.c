#include <stdio.h>
#include <stddef.h>
#include "main.h"

/**
 * parsing_user_input - split an input into tokens
 * @line: string - string written by the user
 *
 * Return: array of strings - array of every arguments
 */

char **parsing_user_input(char *line)
{
	int size_of_token = 80;
	int i = 0;
	struct stat st;

	char **tokens = malloc(sizeof(char *) * size_of_token);

	if (tokens == NULL)
	{
		fprintf(stderr, "Allocation failed");
		exit(EXIT_FAILURE);
	}

	char *token = strtok(line, " ");

	if (token == NULL)
	{
		tokens[0] = NULL;
		return (tokens);
	}

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);

}

/**
 * check_if_command_exists - use the stat func to check if cmd exists
 * @arg: string - tokens[0] in the main function
 *
 * Return: int - 0 if it exists - 1 if it doesn't
 */

int check_if_command_exists(*arg)
{
	struct stat st;

	if (stat(arg, &st) == 0)
		return (0);
	else
		return (1);

}


