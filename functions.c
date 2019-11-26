#include "holberton.h"
#include <stdio.h>
/**
 **_strcmp - compares two strings
 *
 *@s1: is a pointer
 *@s2: is a pointer
 * Return: On succes number.
 * On error.
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = -1;
	do {
		i++;
		if (s1[i] == '\0')
		{
			return (s1[i] - s2[i]);
		}
	} while (s1[i] == s2[i]);
	return (s1[i] - s2[i]);
}

/**
 * pEnv - print the enviroment
 *
 *@env: is a character
 * Return: On succes 1.
 * On error.
 */

void pEnv(char **env)
{
	int i = 0;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

/**
  * execute - execute
  *
  *@toc: is a pointer
  *@av: is a double pointer
  *@env: is a double pointer
  * Return: On succes none.
  * On error.
  */

void execute(char *av[], char **env)
{
	char pat;

	pat = _path(av[0], env);
	execve(pat, (av + 1), env);
}

/**
 * _path - path
 *
 *@env : is a double pointer
 * Return: On succes none.
 * On error.
 */

char _path(char *av, char **env)
{
	struct stat status;

	(void)env;
	if (stat(av, &status) == 0)
		return (av);
	return (av);
}
