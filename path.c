#include "shell.h"

/**
 * _strcpy - copies a string to another.
 * @src: source string.
 * @dest: destination string.
 * Return: pointer.
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int len = 0;

	while (*(src + len) != '\0')
		len++;

	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * executepath - function to access a specific PATH.
 * @p: directory to access
 * @tokens: array of tokens.
 */
void executepath(char *p, char **tokens)
{
	int stat, len1, len2;
	pid_t child;
	char *newp = NULL;

	for (len1 = 0; *(p + len1) != '\0'; len1++)
		;

	for (len2 = 0; tokens[0][len2] != '\0'; len2++)
		;

	newp = malloc(sizeof(char) * (len1 + len2 + 2));

	_strcpy(newp, p);
	_strcat(newp, "/");
	_strcat(newp, tokens[0]);

	newp[(len1 + len2 + 1)] = '\0';
	child = fork();
	if (child == 0)
	{
		if (access(newp, X_OK) == 0)
			execve(newp, tokens, environ);
	}
	else
		while (waitpid(-1, &stat, 0) != child)
			;

	if (stat == 0)
		errno = 0;

	free(newp);
}

/**
 * searchpath - function to search a specific PATH.
 * @p: part of the PATH.
 * @tokens: array of tokens.
 * Return: int.
 */
int searchpath(char *p, char **tokens)
{
	struct dirent *de;
	int reached = 0, onpath = -1;

	p = strtok(p, ":");
	while (p != NULL && reached != 1)
	{
		DIR *dr = opendir(p);

		while ((de = readdir(dr)) != NULL)
		{
			if (_strcmp(de->d_name, tokens[0]) == 0)
			{
				executepath(p, tokens);
				onpath = 0;
				reached = -1;
				break;
			}
		}
		closedir(dr);
		if (reached == 0)
			p = strtok(NULL, ":");
	}
	return (onpath);
}

/**
 * findonpath - find a PATH in environ.
 * @tokens: array of tokens.
 * Return: int.
 */
int findonpath(char **tokens)
{
	int i = 0, onpath;
	char *p = NULL;
	char *path = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp("PATH=", environ[i], 5) == 0)
		{
			path = _strdup(environ[i]);
			strtok(path, "=");
			p = strtok(NULL, "=");
			onpath = searchpath(p, tokens);
			break;
		}
	}
	free(path);

	return (onpath);
}
