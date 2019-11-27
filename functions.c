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
 * execute - execute
 *
 *@av: is a double pointer
 *@env: is a double pointer
 * Return: On succes none.
 * On error.
 */

void execute(char *av[], char *env[])
{
	char *pat;
	int error = 0;

	pat = _path(av[0], env);
	error = execve(pat, (av + 0), env);
	if (error == -1)
	{
		perror("error");
		free(pat);
		exit(0);
	}
}

/**
 * _path - path
 *
 *@av : is a char
 *@env : is a double pointer
 * Return: On succes none.
 * On error.
 */

char *_path(char av[], char *env[])
{
	char *cpy, *token, *dir;
	int i = 0, j = 0;
	struct stat status;

	if (stat(av, &status) == 0)
		return (av);
	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], "PATH=", 5) == 0)
		{
			break;
		}
	}
	cpy = _strdup(env[i]);
	token = strtok(cpy, ":");
	for (j = 0; token != NULL; j++)
	{
		dir = malloc((_strlen(token) + _strlen(av) + 10) * sizeof(char));
		_strcat(dir, token);
		if (dir[j - 1] != '/')
			_strcat(dir, "/");
		_strcat(dir, av);
		if (stat(dir, &status) == 0)
			return (dir);
		token = strtok(NULL, ":");
	}
	free(dir);;
	free(cpy);
	return (av);
}


/**
 **_strdup - copy a strings
 *
 *@str: is a pointer
 * Return: On succes string.
 * On error.
 */

char *_strdup(char *str)
{
	unsigned int i, j;
	char *m;

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i]; i++)
		;
	i++;
	m = malloc(i * sizeof(char));
	if (m == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		m[j] = str[j];
	}
	return (m);

}

/**
 * _strlen - return de lenght of a string
 *
 *@s: is a pointer
 * Return: On succes lenght oa a string.
 * On error.
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != 0; i++)
	{
	}
	return (i);
}
