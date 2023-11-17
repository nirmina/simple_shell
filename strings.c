#include "shell.h"
/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 * Return: pointer to the duplicated string
 * */
char *_strdup(const char *str)
{
char *ptr;
int i, length = 0;
if (!str)
return (NULL);
while (*str != '\0')
{
length++;
str++;
}
str = str - length;
ptr = malloc(sizeof(char) * (length + 1));
if (ptr == NULL)
return (NULL);
for (i = 0; i <= length; i++)
ptr[i] = str[i];
return (ptr);
}
/*
 * _strcmp - Compare two strings.
 *  @s1: The first string to be compared.
 *  @s2: The second string to be compared.
 *  Return: Negative value if s1 is less than s2, 0 if they are equal,
 *  or positive value if s1 is greater than s2.
 *  */
int _strcmp(char *s1, char *s2)
{
int cmp;
cmp = (int)*s1 - (int)*s2;
while (*s1)
{
if (*s1 != *s2)
break;
s1++;
s2++;
cmp = (int)*s1 - (int)*s2;
}
return (cmp);
}
/**
 * _strlen - returns the string len
 * @s: the source
 * * Return: the length
 * */
int _strlen(char *s)
{
int len = 0;
while (s[len])
len++;
return (len);
}
