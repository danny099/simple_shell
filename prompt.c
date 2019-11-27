#include "holberton.h"
/**
 *main - is a main
 *@ac: is a int
 *@av: is a pointer
 *@env: is a pointer
 *Return: 0
 */
int main(int ac, char *av[], char *env[])
{
	pid_t son;
	size_t size = 0;
	int read = 0, i = 0, status;
	char *string = NULL, *token, *toc[32];

	(void)ac;
	(void)av;
	while (1)
	{
		write(1, "$ ", 2);
		read = getline(&string, &size, stdin);
		if (read == -1)
		{
			write(1, "\n", 1);
			return (0);
		}
		if (read > 1)
		{
			token = strtok(string, " \t\n\r");
			for (i = 0; i < 32 && token != NULL; i++)
			{
				toc[i] = token;
				token = strtok(NULL, " \t\n\r");
			}
			if (_strcmp(string, "exit") == 0)
			{
				free(string);
				exit(0);
			}
			toc[i] = NULL;
			son = fork();
			if (son < 0)
				perror("Fail son"), exit(0);
			if (son == 0)
				execute(toc, env);
			if (son > 0)
				wait(&status);
		}
	}
	write(1, "\n", 1);
	free(string);
	return (0);
}
