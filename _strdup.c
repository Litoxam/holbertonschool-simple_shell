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
	unsigned int i; /* index pour copier la string */
	unsigned int length = 0; /* longueur de la string */

	if (str == NULL) /*si la chaine est nulle, on retourne NULL*/
		return (NULL);

	while (str[length] != '\0') /*on check la longueur de la string str*/
		length++;

	/* on réserve un espace +1 pour le \0 */
	copy = malloc(sizeof(char) * (length + 1));

	if (copy == NULL) /*on vérifie si on a eu l'espace nécessaire*/
		return (NULL);

	for (i = 0; i <= length; i++) /*on copie str sur copy*/
		copy[i] = str[i];

return (copy);/* on retourne copy */

}
