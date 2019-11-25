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

	while (1)
	{
		write(1, "$ ", 2);
		string = (char *) malloc(size);
		read = getline(&string, &size, stdin);
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
		    son == 0 ? execve(toc[0], toc, NULL) : wait(&status);
		  }
	}
	return (0);
}
