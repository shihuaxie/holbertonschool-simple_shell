#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * get_path - get PATH string from environ
 * Return: pointer to PATH value or NULL
 */
char *get_path(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
	}
	return (NULL);
}

/**
 * build_path - full path for a command
 * @directory: directory string
 * @command: command string
 * Return: malloc'd full path or NULL
 */
char *build_path(char *directory, char *command)
{
	int length;
	char *full_path;

	length = strlen(directory) + strlen(command) + 2;
	full_path = malloc(sizeof(char) * length);
	if (full_path == NULL)
		return (NULL);

	sprintf(full_path, "%s/%s", directory, command);
	return (full_path);
}

/**
 * find_command - Simple shell 0.3
 * @command: Handle the PATH
 * Return: NULL if not found
 */
char *find_command(char *command)
{
	char *path, *path_copy, *full_path, *directory;

	if (command == NULL)
		return (NULL);
	if (*command == '/' || *command == '.')
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		else
			return (NULL);
	}

	path = get_path();
	if (path == NULL)
		return (NULL);
	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	directory = strtok(path_copy, ":");
	while (directory != NULL)
	{
		if (strlen(directory) == 0)
			directory = ".";
		full_path = build_path(directory, command);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		directory = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
