#include "main.h"

/**
 * _getenv - gets an environment variable
 * @target: the name of the variable to find
 * Return: string - pointer to the value, or NULL
 */

char *_getenv(const char *target)
{
	int i, length;


	length = 0;
	while (target[length]) /*measure the length of target*/
		length++;


	for (i = 0; environ[i]; i++)
	{
/* compare target string with environment variable and check for '=' */
		if (strncmp(environ[i], target, length) == 0 && environ[i][length] == '=')
		{   /*returns a pointer to the char after '=' */
			return (&environ[i][length + 1]);
		}
	}

	return (NULL);
}
