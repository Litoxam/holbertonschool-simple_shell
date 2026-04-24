#include "main.h"
#include <errno.h>

/**
 * add_arg_to_path - add a / and arg at the end of a path
 * @arg: char - first arg read by getline
 * @full_path: string - space allocated for full path
 * @dir: string - directory to check
 * Return: nothing
 */
void add_arg_to_path(char *full_path, char *dir, char *arg)
{
	strcpy(full_path, dir);
	strcat(full_path, "/");
	strcat(full_path, arg);
}

/**
 * is_executable - checks if a file exists and is executable
 * @path: pointer to string - full path to check
 * Return: 1 if executable, 0 otherwise
 */
int is_executable(char *path)
{
	struct stat st;

	if (stat(path, &st) == -1 || S_ISDIR(st.st_mode))
		return (0);
	if (access(path, X_OK) == 0)
		return (1);
	errno = EACCES;
	return (0);
}

/**
 * search_in_path - searches for a command in PATH dirs
 * @env_copy: pointer to string - copy of PATH string
 * @arg: pointer to string - command to find
 * Return: pointer to string - full path if found, NULL otherwise
 */
char *search_in_path(char *env_copy, char *arg)
{
	char *start, *end, *dir, *full_path;
	int saved_errno;

	saved_errno = ENOENT;
	start = env_copy;
	while (start)
	{
		end = strchr(start, ':');
		if (end != NULL)
			*end = '\0';
		dir = (*start == '\0') ? "." : start;
		full_path = malloc(strlen(dir) + strlen(arg) + 2);
		if (full_path != NULL)
		{
			add_arg_to_path(full_path, dir, arg);
			if (is_executable(full_path))
				return (full_path);
			if (errno == EACCES)
				saved_errno = EACCES;
			free(full_path);
		}
		start = (end != NULL) ? end + 1 : NULL;
	}
	errno = saved_errno;
	return (NULL);
}

/**
 * get_cmd_path - find the cmd in the PATH
 * @arg: char - first arg read by getline
 * Return: return the full_path if found - else return NULL
 */
char *get_cmd_path(char *arg)
{
	char *env, *env_copy, *result;

	if (!arg)
		return (NULL);
	if (strchr(arg, '/'))
	{
		if (is_executable(arg))
			return (_strdup(arg));
		errno = EACCES;
		return (NULL);
	}
	env = _getenv("PATH");
	if (!env)
		return (NULL);
	env_copy = _strdup(env);
	if (!env_copy)
		return (NULL);
	result = search_in_path(env_copy, arg);
	free(env_copy);
	return (result);
}

