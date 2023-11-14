#include <unistd.h>
#include <stdio.h>
/**
 * main - to test the function getppid (the processor of the parent function)
 * Return: 0
 */
int main(void)
{
pid_t ppid;
ppid = getppid();
printf("the parent of the child processor is = %d\n", ppid);
return (0);
}
