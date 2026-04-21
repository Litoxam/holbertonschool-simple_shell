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
/**
 * struct builtin_s - Built-ins structure
 *
 * @name: name of the command built-in
 * @f: function pointer handling the command
 */ 
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
int handle_env(char **args);
int check_builtins(char **args);
int _atoi(char *s);
char *get_cmd_path(char *arg);
void process_cmd(char **args);

#endif
