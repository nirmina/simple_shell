#include "shell.h"
/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
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
