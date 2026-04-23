#include "main.h"

/**
 * execute_cmd_line - executes command line given in args
 * @args: pointer to array of char - path to the cmd line to execute
 *
 * Return: int - (0) on success - (1) on fork failure - (98) if execve failed
 */

int execute_cmd_line(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}

	if (child_pid == 0)
	{
		execve(args[0], args, environ);
		exit(EXIT_FAILURE);
	}
	waitpid(child_pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));

	return (0);
}
