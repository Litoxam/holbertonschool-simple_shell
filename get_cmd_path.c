#include "main.h"

/**
 * get_cmd_path - find the cmd in the PATH
 * @arg: char - first arg read by getline
 * Return: return the full_path if found - else return NULL
 */

char *get_cmd_path(char *arg)
{

	char *env;
	char *env_copy;
	char *dir;
	char *full_path;


	env = _getenv("PATH");
	env_copy = strdup(env);
	dir = strtok(env_copy, ":");

	while (dir != NULL)
	{

		full_path = malloc(strlen(dir) + strlen(arg) + 2);
		if (full_path == NULL)
		{
			free(env_copy);
			return (NULL);
		}
		if (full_path != NULL)
		{
			strcpy(full_path, dir);
			strcat(full_path, "/");
			strcat(full_path, arg);
		}
		if (access(full_path, X_OK) == 0) /*use of access instead of stat*/
		{
			free(env_copy);
			return (full_path);
		}
		else
			{
				free(full_path);
				dir = strtok(NULL, ":");
			}
	}
	free(env_copy);
	return (NULL);
}
