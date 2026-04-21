#ifndef MAIN_H
#define MAIN_H

/*libraries*/
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Structures */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **args);
} builtin_t;

extern char **environ;

/*prototypes*/
char **parsing_user_input(char *line);
int check_if_command_exists(char *arg);
int execute_cmd_line(char **args);
int handle_exit(char **args);
int _atoi(char *s);

#endif
