#include "main.h"
#include <unistd.h>
/**
 * _putchar - its a function that prints the character c to the stdout
 * @n: the character that we need to print
 * Return: 1 (on success), -1 (on failure)
 */
int _putchar(char n)
{
return (write(1, &n, 1));
}
