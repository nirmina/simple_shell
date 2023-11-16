#include "shell.h"
/**
 * _exe - executes the command
 * @cmd: the command
 * @argv: something
 * Return: return the exit status
 */
int _exe(char **cmd, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			_free2D(cmd);
			exit(0);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		_free2D(cmd);
	}
	return(WEXITSTATUS(status));
}
