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
	char *env, *env_copy, *dir, *full_path;
	char *start, *end;

	env = _getenv("PATH");
	env_copy = strdup(env);

	if (!env_copy)
		return (NULL);

	start = env_copy;
	while (start != NULL)
	{
		end = strchr(start, ':');
		if (end != NULL)
			*end = '\0';
		if (*start == '\0') /* :: case*/
			dir = ".";
		else
			dir = start;

		full_path = malloc(strlen(dir) + strlen(arg) + 2);

		if (full_path)
		{
			add_arg_to_path(full_path, dir, arg);

		if (access(full_path, X_OK) == 0) /*use of access instead of stat*/
		{
			free(env_copy);
			return (full_path);
		}

		free(full_path);
		}
		if (end == NULL)
			break;
		start = end + 1;
	}
	free(env_copy);
	return (NULL);
}


