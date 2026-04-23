#include "main.h"

/**
 * parsing_user_input - split an input into tokens
 * @line: string - string written by the user
 * Return: array of strings - array of every arguments
 */

char **parsing_user_input(char *line)
{
	int i = 0, len = 0, size_of_token = 80;
	char *ptr, *end;
	char **tokens, **tmp;

	tokens = malloc(sizeof(char *) * size_of_token);
	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';

	if (tokens == NULL)
		exit(EXIT_FAILURE);
	ptr = line;
	while (*ptr != '\0')
	{
		while (*ptr == ' ' || *ptr == '\t')
			ptr++; /*ignores extra spaces*/
		if (*ptr == '\0') /*end of line*/
			break;

		tokens[i] = ptr;
		i++;
		if (i >= size_of_token) /*if the buffer isn't big enough, realloc*/
		{
			size_of_token += 80;
			tmp = realloc(tokens, size_of_token * sizeof(char *));
			if (tmp == NULL)
				exit(EXIT_FAILURE);
			tokens = tmp;
		}
		end = strpbrk(ptr, " \t"); /*looks for separator after a token*/
		if (end) /*if separator found*/
		{
			*end = '\0';
			ptr = end + 1;
		}
		else
			break;
	}
	tokens[i] = NULL;
	return (tokens);
}
