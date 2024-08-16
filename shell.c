#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT "#cisfun$ "

void execute_command(char *command);

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *command;

    while (1)
    {
        
        printf("%s", PROMPT);

       
        read = getline(&line, &len, stdin);
        if (read == -1) 
        {
            if (line)
                free(line);
            printf("\n");
            break;
        }

       
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';


        execute_command(line);
    }

    return 0;
}

void execute_command(char *command)
{
    char *argv[] = {command, NULL};
    

    if (execve(command, argv, NULL) == -1)
    {
        perror("./shell"); 
    }
}

