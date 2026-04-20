#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stdlib.h>

extern char **environ;

int execute_cmd_line(char **args);

#endif
