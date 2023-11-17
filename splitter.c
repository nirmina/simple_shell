#include "shell.h"
/**
 * splitter - remove delimetres from the read line
 * @line: the read line
 * Return: strings of the line
 */
char **splitter(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **cmd = NULL;
	int i = 0, count = 0;

	if (line == NULL)
		return(NULL);
	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	if (!token)
	{
		free(tmp), tmp = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	cmd = malloc(sizeof(char *) * (count + 1));
	if (cmd == NULL)
	{
		free(line);
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
