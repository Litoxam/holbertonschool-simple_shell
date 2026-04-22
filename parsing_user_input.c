#include "main.h"

/**
 * parsing_user_input - split an input into tokens
 * @line: string - string written by the user
 *
 * Return: array of strings - array of every arguments
 */

char **parsing_user_input(char *line)
{
	int i = 0, len = 0, size_of_token = 80;
	char *ptr;
	char **tokens;

	tokens = malloc(sizeof(char *) * size_of_token);
	if (tokens == NULL)
	{
		fprintf(stderr, "Allocation failed");
		exit(EXIT_FAILURE);
	}
	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';

	ptr = line;
	while (*ptr != '\0')
	{
		while (*ptr == ' ' || *ptr == '\t')
			ptr++;
		if (*ptr == '\0')
			break;

		tokens[i] = ptr;
		i++;
		if (i >= size_of_token) /*if the buffer isn't big enough, realloc*/
		{
			size_of_token += 80;
			tokens = realloc(tokens, size_of_token * sizeof(char *));
		}
		while (*ptr != ' ' && *ptr != '\t' && *ptr != '\0')
			ptr++;
		if (*ptr != '\0')
		{
			*ptr = '\0';
			ptr++;
		}
	}
	tokens[i] = NULL;
	return (tokens);
}
