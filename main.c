#include "main.h"

/**
 * main - entry point
 * Return: 0 if success
 */

int main(void)
{
	char **args, *line = NULL;
	size_t n = 0;
	ssize_t user_input;

	while (1)
	{
		printf("<3 ");
		user_input = getline(&line, &n, stdin);
		if (user_input == -1)
			break;
		args = parsing_user_input(line);

		if (args != NULL && args[0] != NULL)
			process_cmd(args);

		free(args);
	}
	free(line);
	return (0);
}

/**
 * process_cmd - Processes the command and arguments
 * @args: array of strings - containing the command and arguments
 */

void process_cmd(char **args)
{
	char *path;

	if (check_builtins(args) != -1)
		return;

	if (check_if_command_exists(args[0]) == 1)
	{
		path = get_cmd_path(args[0]);

		if (path != NULL)
		{
			args[0] = path;
			execute_cmd_line(args);
			free(path);
		}
		else
			printf("Command doesn't exist\n");
	}
	else
		execute_cmd_line(args);
}
