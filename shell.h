#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
/* strings declaration : */
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
/* freer header */
void _free2D(char **array);

#define DELIM " \t\n"
extern char **environ;
int _exe(char **cmd, char **argv);
char **splitter(char *line);
char *line_reader(void);
int _putchar(char n);
#endif
