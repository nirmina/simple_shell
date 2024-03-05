#include "shell.h"
#include <string.h>
/**
 * _setenv - initialize a new environment variable, or modify an existing one
 * @nom: nom de lenvironnement
 * @value: associated to the envirement variable
 * @overwrite: flag indicate wether to overwrite the enviroment variable exist
 * Return: int
 */
int _setenv(char *nom, char *value, int overwrite)
{
int i = 0, length = 0;
char *new_value;
if (!nom || !value)
return (-1);
while (environ[i])
{
length = _strlen(nom);
if (strncmp(environ[i], nom, length) == 0)
{
if (overwrite)
{
new_value = malloc(strlen(nom) + strlen(value) + 2);
_strcpy(new_value, nom);
_strcat(new_value, "=");
_strcat(new_value, value);
environ[i] = new_value;
return (0);
}
return (0);
}
i++;
}
new_value = malloc(strlen(nom) + strlen(value) + 2);
_strcpy(new_value, nom);
_strcat(new_value, "=");
_strcat(new_value, value);
environ[i] = new_value;
environ[i + 1] = NULL;
return (0);
}
