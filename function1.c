#include <stdio.h>
#include <stdlib.h>
#include "mainshell.h"
/**
 * my_getline - a function that reads a line from a File
 * @line: a pointer to the buffer where the line we enter will be stored
 * @b: a pointer to the size of the buffer
 * @stream: a File or program that is considered as input it could be stdin
 * Return: Success (number of characters read), Failure (-1)
 * redefinition de la methode getline()
 */
ssize_t my_getline(char **line, int *b, FILE *stream)
{
int j = 0;
int c;
char *r = (char *)malloc(*b);
if (!line || !b || !stream)
{
return (-1);
}
if (!(*line) || *b == 0)
{
*b = 128;
*line = (char *)malloc(*b);
if (*line == NULL)
{
return (-1);
}
}
while (((c = fgetc(stream)) != EOF) && c != '\n')
{
(*line)[j++] = (char)c;
if (j == *b - 1)
{
*b = (*b) * 2;
if (!r)
{
return (-1);
}
*line = r;
}
}
if (j > 0 || c != EOF)
{
return (j);
}
else
{
return (-1);
}
}
