#include "main.h"

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
 * get_cmd_path - find the cmd in the PATH
 * @arg: char - first arg read by getline
 * Return: return the full_path if found - else return NULL
 */

char *get_cmd_path(char *arg)
{
	char *env_copy, *start, *env, *end, *full_path, *dir;

	env = _getenv("PATH");
	if (!env || !arg)
		return (NULL);

	env_copy = _strdup(env);
	if (!env_copy)
		return (NULL);
	start = env_copy;

	while (start)
	{
		end = strchr(start, ':');
		if (end != NULL)
			*end = '\0';
		if (*start == '\0')
			dir = ".";
		else
			dir = start;

		full_path = malloc(strlen(dir) + strlen(arg) + 2);
		if (full_path != NULL)
		{
			add_arg_to_path(full_path, dir, arg);
			if (access(full_path, X_OK) == 0)
			{
				free(env_copy);
				return (full_path);
			}
			free(full_path);
		}
		if (end != NULL)
			start = end + 1;
		else
			start = NULL;
	}
	free(env_copy);
	return (NULL);
}

