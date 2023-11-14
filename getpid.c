#include <unistd.h>
#include <stdio.h>
/**
 * main - to test the getpid function and khow the id of the current processor
 * Return: 0
 */
int main(void)
{
pid_t pid;
pid = getpid();
printf("the pid is = %d\n", pid);
return (0);
}
