#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>

extern char **environ;

size_t count_tokens(const char *s);
char **tokenize_line(char *line);
void free_argv(char **argv);
int only_spaces(char *line);
int handle_builtin(char **argv);
char *find_command(char *command);
int check_file(char **av);

#endif
