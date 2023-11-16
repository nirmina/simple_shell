#include "shell.h"
/**
 * line_reader - reads the line
 */
char *line_reader(void)
{
	char *line = NULL; /* buffer */
	size_t size = 0; /* sizeof the line(buffer) */
	ssize_t n_char = 0;
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n_char = getline(&line, &size, stdin);
	if (n_char == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
