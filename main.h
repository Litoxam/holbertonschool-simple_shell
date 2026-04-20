#ifndef MAIN_H
#define MAIN_H

/*libraries*/

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stddef.h>

/*prototypes*/

int main(int argc, char **argv);
char **parsing_user_input(char *line);
int check_if_command_exists(char *arg);



#endif
