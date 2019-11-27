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

/**
 * _strncmp - strncmp
 * @s1: is a char
 * @s2: is a char
 * @n: is a size_t
 * Return: On succes 
 * On error.
 */
int _strncmp(char *s1,char *s2, size_t n)
{
	while ((*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}
