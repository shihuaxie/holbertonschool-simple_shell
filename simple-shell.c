#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
extern char **environ;

int main()
{
	char *line;
	size_t buffer_size = 0;
	int child;
	char *argv[] = {NULL, NULL};
	int running = 0;

	child = fork();

	if (child == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		while (running == 0)
		{
			printf("#cisfun$: ");
			if (getline(&line, &buffer_size, stdin) == 1)
			{
				perror("getline failed\n");
				free(line);
				return (1);
			}
			line[strcspn(line, "\n")] = '\0';
			argv[0] = line;
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("./shell");
			}
		}
	}
	else
		{
			wait(NULL);
		}
}
