#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* Macros */
#define PROMPT "#cisfun$ "

/* Function Prototypes */
void execute_command(char *command);

#endif /* SHELL_H */

