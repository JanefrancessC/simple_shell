#include "shell.h"

/**
 * _strlen - calculates string length.
 * @s: the string 
 * Return: the length 
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - string comparison.
 * @s1: string 1
 * @s2: string 2
 * Return: a negative integer if different or postive if same
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * char_finder - checks if a command is started with a character.
 * @haystack: string to search
 * @needle: the character(s) to find
 * Return: &(pte to the haystack) or NULL on failure
 */
char *char_finder(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
