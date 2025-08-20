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
/*	char *argv[] = {NULL, NULL}; */
	int tty = 1, exec_return = 0, i = 0, len = 0;
	(void)ac;
	line = malloc(buffer_size + 1);
	tty = isatty(STDIN_FILENO);

	while (1)
	{
		if (tty == 1)
			printf("#cisfun$: ");
		nread = getline(&line, &buffer_size, stdin);
		if (nread == 1)
		{
			perror("getline failed\n");
			free(line);
			return (1);
		}
		if (nread == -1)
		{
			break;
		}
		line[strcspn(line, "\n")] = '\0';
		av = tokenize_line(line);
		/* argv[0] = line; */
		child = fork();

		if (child < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			/* exec_return = execve(argv[0], argv, environ); */
			exec_return = execve(av[0], av, environ);
			if (exec_return == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		wait(NULL);

		while (*av[i] != '\0')
		{
                	i++;
                	len++;
        	}
        	i = 0;
                while (i < len)
                {
                       	free(av[i]);
                       	i++;
                }
        	
        	free(av);
		free(line);
	}
	return (0);
}

