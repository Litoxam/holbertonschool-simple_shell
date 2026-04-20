#include <stdio.h>
#include <stddef.h>


/**
 * main - entry point
 * @argc: int - number of arguments, set to (void)
 * @argv: pointer of array of char - array of args written in stdin
 *
 * Return: 0 if success
 */



int main(int argc, char **argv)
{

	(void)argc;
	char *buffer = NULL;
	size_t n = 0;
	ssize_t user_input;

	printf("<3 ");

	while (user_input = getline(&buffer, &n, stdin) != -1)
	{

		printf("<3 ");

	}

	return (0);

}
