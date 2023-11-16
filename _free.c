#include "shell.h"
/**
 * _free2D - frees 2D array
 * @array: the source
 */
void _free2D(char **array)
{
	int i;
	if (array == NULL)
		return;
	for (i = 0; array[i] != '\0'; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}
