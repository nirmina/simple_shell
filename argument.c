#include <stdio.h>
/**
 * main - a program that prints all the arguments, without using ac
 * @ac: is the number of items in av its the counter
 * @av: representone of the command line its a pointer
 * Return: 0
 */
int main(int ac, char *av[])
{
int i;
int nbargument = 0;
(void) ac;
for (i = 1; av[i] != NULL; i++)
{
printf("argument est %d : %s\n", i, av[i]);
nbargument += i;
}
printf("nombre dargument total est %d\n", nbargument);
return (0);
}
