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
#define DELIM " \t\n"
/* tools */
void print_err(char *name, char *cmd, int idx);
void reverse_str(char *str, int len);
char *_atoi(int n);

/* strings declaration : */
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
/* freer header */
char *_getenvr(char *var);
void free2D(char **str);
extern char **environ;
int _exe(char **cmd, char **argv, int idx);
char **splitter(char *line);
char *line_reader(void);
int _putchar(char n);
void shell_exit(char **command, int status);
void _env(char **command, int status);
void builtin_handle(char **command, char **argv, int status);
int _setenv(char *nom, char *value, int overwrite);
int built_in(char *command);
char *_getpath(char *command);
#endif
