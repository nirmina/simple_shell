#include "shell.h"
/**
 * splitter - remove delimetres from the read line
 * @line: the read line
 * Return: strings of the line
 */
char **splitter(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **tokens = NULL;
	int i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	if (tmp == NULL)
	{
		return (NULL);
	}
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(line);
		free(tmp);
		return (NULL);
	}
	while (token != NULL)
	{
		i++;
		tokens = realloc(tokens, sizeof(char *) * i);
		if (tokens == NULL)
		{
			free(line);
			free(tmp);
			return (NULL);
		}
		tokens[i - 1] = token;
		token = strtok(NULL, DELIM);
	}
	i++;
	tokens = realloc(tokens, sizeof(char *) * i);
	if (tokens == NULL)
	{
		free(line);
		free(tmp);
		return (NULL);
	}
	tokens[i - 1] = NULL;
	free(line);
	return (tokens);
}
