#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>

size_t count_tokens(const char *s);
char **tokenize_line(char *line);
void free_argv(char **argv);
int only_spaces(char *line);
int handle_builtin(char **argv);

#endif
