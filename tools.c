#include "shell.h"
/**
 * _atoi - integer to char
 * @n : the source
 * Return: the converted char
 */
char *_atoi(int n)
{
	char buff[20];
	int i = 0;

	if (n == 0)
		buff[i++] = '0';
	else
	{
		while (n > 0)
		{
			buff[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buff[i] = '\0';
	reverse_str(buff, i);
	return (_strdup(buff));
}
/**
 * reverse_str - reverse a string
 * @str: the string
 * @len: the length
 * Return: the reversed string
 */
void reverse_str(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
/**
 * print_err - prints the error if fails
 * @name: name of the error
 * @cmd: the command
 * @idx: the error num
 */
void print_err(char *name, char *cmd, int idx)
{
	char *index, msg[] = ": not found";

	index = _atoi(idx);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(index);
}
