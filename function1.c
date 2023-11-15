#include <stdio.h>
#include <stdlib.h>
#include "mainshell.h"
/**
 * getline - a function that read a line from a File
 * @lineptr: a pointer to the buffer where the line we enter will be stored
 * @n: a pointer to the size of the buffer
 * @stream: a File or program that is considered as an input it could be astdin
 * Return: Success (number of character read) , Failure (-1)
 * redefinition de la methode getline()
 */
ssize_t getline(char **lineptr, int *n, FILE *stream)
{
if (!lineptr || !n || !stream)
{
return (-1);
}
if (!(*lineptr) || !n == 0)
{
*n = 128;
*lineptr = (char *)malloc(sizeof(*n));
if (*lineptr == NULL)
{
return (-1);
}
}
int j = 0, c;
while ((c = feof(stream) != EOF) && c != '\n')
{
*lineptr[j++] = (char) c;
if (j == *n - 1)
{
*n = (*n) * 2;
char *r = (char *)malloc(*lineptr, *n);
if (!r)
{
return (-1);
}
*lineptr = r;
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
