#include "main.h"

/**
 * main - entry point
 * Return: 0 if success
 */

int main(void)
{
	char **args;
	size_t n = 0;
	ssize_t user_input;
	int checker;
	char *path, *line = NULL;

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
		if (checker == 1)
		{
			path = get_cmd_path(args[0]);

			if (path != NULL)
			{
				args[0] = path;
				execute_cmd_line(args);
			}
			else
				printf("Command doesn't exist\n");
		}
		else
			execute_cmd_line(args);

		free(args);
	}
	free(line);
	return (0);

}
