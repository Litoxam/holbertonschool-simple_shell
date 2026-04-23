#include "main.h"

/**
 * *_strdup - copy an original string into allocated space
 * @str: original string to cpy
 *
 * Return: NULL if str == 0 or if malloc fails
 *			return copy
 */


char *_strdup(char *str)

{
	char *copy;
	unsigned int i;
	unsigned int length = 0;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;


	copy = malloc(sizeof(char) * (length + 1));

	if (copy == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		copy[i] = str[i];

return (copy);

}
