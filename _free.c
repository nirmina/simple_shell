#include "shell.h"
/**
 * free2D - frees 2D array
 * @str : the source
 */
void free2D(char **str)
{
	int i;

	if (str == NULL)
		return;
	for (i = 0; str[i]; i++)
	{
		free(str[i]);
	}
	free(str);
}
