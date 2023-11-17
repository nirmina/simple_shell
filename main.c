#include "shell.h"
/**
 * main - the main function of simple shell project
 * @argc: count of args
 * @argv: the value of args
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	char **command = NULL;
	int status = 0;
	(void) argc;

	while (1)
	{
		line = line_reader();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		command = splitter(line);
		if (!command)
			continue;
			
		status = _exe(command, argv);
	}
}		
