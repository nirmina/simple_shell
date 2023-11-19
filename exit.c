#include "shell.h"
/**
 * built_in - a function that verifie if acommand is a builtin
 * @command: its a shell command
 * Return: 1 (its a built in) , 0 (its not)
 */
int built_in(char *command)
{
	char *builts[] = {"exit", "env"};

	if (_strcmp(command, builts[0]) == 0 || _strcmp(command, builts[1]) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * shell_exit - a function that exit the shell
 * @command: its a shell command
 * @status: to indicate if the command has been executed succesufuly or has
 * encountered an error
 * Return: void
 */
void shell_exit(char **command, int status)
{
	free2D(command);
	exit(status);
}
/**
 * _env - a function that print all envirement
 * @command: shell command
 * @status: if its been executed succesfully
 * Return: void
 **/
void _env(char **command, int status)
{
	int i;
	(void) status;
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free2D(command);
}
/**
 * builtin_handle - a function that handle eash case
 * @command: its a shell command
 * @status: indicate if a command has been executed succesfully or not
 * @argv: argument vector
 * Return: void
 */
void builtin_handle(char **command, char **argv, int status)
{
	(void) argv;
	if (_strcmp(command[0], "exit") == 0)
	{
		shell_exit(command, status);
	}
	else if (_strcmp(command[0], "env") == 0)
	{
		_env(command, status);
	}
}
