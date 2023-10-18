#include "shell.h"

/**
 * custom_strcat - Concatenates two strings with a specified length.
 * @dest: The first string to which content will be appended.
 * @src: The second string from which content will be appended.
 * @n: The maximum number of characters to append.
 * Return: A pointer to the destination string.
 */

char *custom_strcat(char *dest, char *src, int n)
{
	int i = 0;
    int j = 0;
	char *result = dest;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++, j++;
	}
	if (j < n)
		dest[i] = '\0';

	return (result);
}


/**
 * _strcat - Concatenates two strings
 * @dest: The first string to which content will be appended.
 * @src: The second string from which content will be appended.
 * Return: A pointer to the destination string.
 */

char *_strcat(char *dest, char *src)
{
	char *result = dest;

	while (*dest)
	{
		dest++;
	}
	
	while (*src)
	{
		*dest++ = *src++;
	}

	*dest = *src;
	return (result);
}
