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
  *@toc: is a pointer
  *@av: is a double pointer
  *@env: is a double pointer
  * Return: On succes none.
  * On error.
  */

void execute(char *av[], char *env[])
{
	char *pat;
	int i = 0;

	printf("%s", av[0]);
	pat = _path(av[0], env);
	i = execve(pat, (av + 0), env);
	if (i == -1)
	  {
	    perror("PUTO");
	    exit;
	  }
}

/**
 * _path - path
 *
 *@env : is a double pointer
 * Return: On succes none.
 * On error.
 */

char *_path(char av[], char *env[])
{
	char *cpy, *token;
	int i = 0;
	struct stat status;

	if (stat(av, &status) == 0)
		return (av);

	cpy = _strdup(env);
	token = strtok(cpy, ":");
	while (token != NULL)
	{

	}
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


