#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int _strncmp(char *s1, char *s2, size_t n);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
void execute(char *av[], char **env);
char *_path(char av[], char *env[]);
int _strcmp(char *s1, char *s2);
#endif
