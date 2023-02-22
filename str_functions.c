#include "shell.h"

/**
 * _strcmp - compares two strings.
 * @s1: first string.
 * @s2: second string.
 *
 * Return: int.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (-1);
	}

	return (0);
}

/**
 * _strncmp - compares two string for a specific len.
 * @s1: first string.
 * @s2: second string.
 * @len: length.
 *
 * Return: int.
 */
int _strncmp(char *s1, char *s2, int len)
{
	for (; *s1 && *s2 && len >= 0; len--)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (-1);
	}

	return (0);
}

/**
 * _strcat - concatenates two strings.
 * @dest: destenation string.
 * @src: source string.
 *
 * Return: pointer.
 */
char *_strcat(char *dest, char *src)
{
	int i, len1, len2;

	len1 = len2 = 0;
	while (*(src + len1) != '\0')
		len1++;

	while (*(dest + len2) != '\0')
		len2++;

	for (i = 0; i <= len1; i++)
		*(dest + (len2 + i)) = *(src + i);

	return (dest);
}
