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
	pid_t son, status;
	size_t size;
	int read, i;
	char *string, *token, *toc[16];

	(void) ac;
	(void) av;
	while (1)
	{
		write(1, "$ ", 2);
		string = (char *) malloc(size);
		read = getline(&string, &size, stdin);
		if (strncmp("env", string, 3) == 0)
			pEnv(env);
		if (strncmp("exit", string, 4) == 0)
			exit(0);
		if (read == -1)
		{
			printf("\n");
			exit(0);
		}
		if (read > 1)
		{
			token = strtok(string, " \n");
			for (i = 0; token != NULL; i++)
			{
				toc[i] = token;
				token = strtok(NULL, " \n");
			}
			toc[i] = NULL;
			son = fork();
			son == 0 ? execve(toc[0], toc, env) : wait(&status);
		}
	}
	return (0);
}
