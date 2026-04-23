#include "main.h"

/**
 * main - entry point
 * @argc: void - number of arguments
 * @argv: array of strings - arguments of the function
 * Return: 0 if success
 */

int main(int argc, char **argv)
{
	char **args, *line = NULL;
	int cmd_return, code;
	size_t n = 0;
	ssize_t user_input;
	int line_number = 0;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("<3 ");

		user_input = getline(&line, &n, stdin);
		if (user_input == -1)
			break;

		line_number++;

		args = parsing_user_input(line);

		if (args != NULL && args[0] != NULL)
		{
			cmd_return = process_cmd(args, argv[0], line_number);
			if (cmd_return == -2)
			{
				code = args[1] ? _atoi(args[1]) : 0;
				free(args);
				free(line);
				exit(code);
			}
		}


		free(args);
	}
	free(line);
	return (0);
}

/**
 * process_cmd - Processes the command and arguments
 * @args: array of strings - containing the command and arguments
 * @prog: name of our programm
 * @line_number: nb of the actual line
 */

int process_cmd(char **args, char *prog, int line_number)
{
	char *path;
	int builtins_return;

	builtins_return = check_builtins(args, prog, line_number);
	if (builtins_return != -1)
		return (builtins_return);

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
			fprintf(stderr, "%s: %d: %s: not found\n", prog, line_number, args[0]);
	}
	else
		execute_cmd_line(args);

	return (0);
}
