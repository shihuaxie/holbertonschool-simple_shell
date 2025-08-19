#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"
/**
 * main - entrypoint to simple shell
 * @ac: Number of args passed to the program
 * @av: Array of arguments
 * Return: 0
 */
extern char **environ;

int main(int ac, char **av)
{
	char *line;
	size_t buffer_size = 256;
	ssize_t nread;
	int child;
	char *argv[] = {NULL, NULL};
	int tty = 1, exec_return = 0;

	line = malloc(buffer_size + 1);
	tty = isatty(STDIN_FILENO);

	while (1)
	{
		if (tty == 1)
			printf("#cisfun$: ");
		/* Save getline's return value into a dedicated value
		 *   to support  multiple if statements
		 */
		nread = getline(&line, &buffer_size, stdin);
		if (nread == 1)
		{
			perror("getline failed\n");
			free(line);
			return (1);
		}
		/* Check for EOF as a separate condition */
		if (nread == -1)
		{
			/* printf("\nExiting shell (EOF)\n"); */
			break;
		}
		line[strcspn(line, "\n")] = '\0';
		argv[0] = line;
		child = fork();

		if (child < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			exec_return = execve(argv[0], argv, environ);
			if (exec_return == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		wait(NULL);
	}
	free(line);
	return (0);
}

