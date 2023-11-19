#include "shell.h"
/**
 * _getpath - get the path
 * @command: our command
 * Return: the path
 */
char *_getpath(char *command)
{
	char *pat_env, *full_cmd, *dir;
	int i;
	struct stat st;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}
	pat_env = _getenvr("PATH");
	if (pat_env == NULL)
		return (NULL);

	dir = strtok(pat_env, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(pat_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(pat_env);
	return (NULL);
}
