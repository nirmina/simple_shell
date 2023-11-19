#include "shell.h"
/**
 * _exe - executes the command
 * @cmd: the command
 * @argv: something
 * @idx: index
 * Return: return the exit status
 */
int _exe(char **cmd, char **argv, int idx)
{
	pid_t pid;
	char *full_command;
	int status;

	full_command = _getpath(cmd[0]);
	if (full_command == NULL)
	{
		print_err(argv[0], cmd[0], idx);
		free2D(cmd);
		return (127);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(full_command, cmd, environ) == -1)
		{
			free(full_command), full_command = NULL;
			free2D(cmd);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free2D(cmd);
		free(full_command), full_command = NULL;
	}
	return (WEXITSTATUS(status));
}
