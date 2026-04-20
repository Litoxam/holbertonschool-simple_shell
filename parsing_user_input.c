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
	int len = 0;

	char **tokens = malloc(sizeof(char *) * size_of_token);

	if (tokens == NULL)
	{
		fprintf(stderr, "Allocation failed");
		exit(EXIT_FAILURE);
	}

	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';

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
