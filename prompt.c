#include "holberton.h"
/**
 * main - read line
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t son, status;
	size_t size;
	int read, i;
	char *string, *token, *toc[16];

	while (read != EOF)
	{
		write(1, "$ ", 2);
		string = (char *) malloc(size);
		read = getline(&string, &size, stdin);
		if (read == -1)
			read = EOF;
		token = strtok(string, " \n");
		for (i = 0; token != NULL; i++)
		{
			toc[i] = token;
			token = strtok(NULL, " \n");
		}
		toc[i] = NULL;
		son = fork();
		if (son == 0)
			execve(toc[0], toc, NULL);
		else
			wait(&status);
	}
	return (0);
}
