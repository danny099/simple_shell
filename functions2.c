#include "holberton.h"
#include <stdio.h>
/**
  **_strcat - concatenates two strings
  *
  *@dest: is a pointer
  *@src: is a pointer
  * Return: On succes string concatenate.
  * On error.
  */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != 0; i++)
	{
		*(dest + i) = dest[i];
	}
	for (j = 0; src[j] != 0; j++)
	{
		*(dest + i) = src[j];
		i++;
	}
	if (src[i] == '\0')
	{
		*(dest + i) = src[i];
	}
	return (dest);
}
