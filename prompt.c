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
			return (127);
		}
		if (read > 1)
		{
			token = strtok(string, " \t\n\r");
			for (i = 0; i < 32 && token != NULL; i++)
			{
				toc[i] = token;
				token = strtok(NULL, " \t\n\r");
			}
			toc[i] = NULL;
			if (_strcmp(toc[0], "env") == 0)
			if (_strcmp(toc[0], "exit") == 0)
				break;
			son = fork();
			if (son == 0)
			{
				execute(toc, env);
			}
			if (son > 0)
				wait(&status);
		}
	}
	write(1, "\n", 1);
	return (0);
}
