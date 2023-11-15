#include <stdio.h>
#include <stdlib.h>
int main (void)
{
char *linebuff;
size_t n = 20;
linebuff = malloc(sizeof(char) * 20);
printf("veuiller entre vos infos:");
getline(&linebuff, &n, stdin);
printf("the infos :%s", linebuff);
printf("size :%ld\n", n);
free(linebuff);
return (0);
}
