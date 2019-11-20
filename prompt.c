#include "holberton.h"
/**
 * main - read line
 *
 * Return: Always 0.
 */
int main()
{
	size_t size;
	int read, i;
	char *string, *token, *toc[16];
	
	while(1)
	{
		write(1, "$ ", 2);
		string = (char *) malloc (size);
		read = getline (&string, &size, stdin);
		if (read == -1)
		{
			printf("error");
		}
		token = strtok(string, " \n");
		for (i = 0; token != NULL; i++)
		{
			toc[i] = token;
			token = strtok(NULL, " \n");
		}
		toc[i] = NULL;
		execve(toc[0], toc, NULL);
	}
	return (0);
}
