#include "simple_shell.h"

/**
 * main - Entry point of the shell program.
 * This function runs an infinite loop to display a prompt,
 *  read input from the user, and execute the command.
 *
 *  Return: Always 0 (Success).
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		prompt_user();
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			printf("\n");
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		if (line[0] != '\0')
		{
			execute_command(line);
		}
	}

	free(line);
	return (0);
}

/**
 * prompt_user - Displays the shell prompt to the user.
 */
void prompt_user(void)
{
	printf("#cisfun$ ");
}

/**
 * execute_command - Executes the command entered by the user.
 * @line: The command entered by the user.
 */
void execute_command(char *line)
{
	char *argv[2];
	pid_t pid;
	int status;

	argv[0] = line;
	argv[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./shell");
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
