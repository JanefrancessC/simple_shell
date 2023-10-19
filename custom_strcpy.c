#include "shell.h"

/**
 * custom_strncpy - Copies a portion of one string to another.
 * @dest: The destination string where content will be copied.
 * @src: The source string from which content will be copied.
 * @n: The maximum number of characters to copy.
 * Return: A pointer to the destination string.
 */
char *custom_strncpy(char *dest, char *src, int n)
{
	int i;
	int j;
	char *result = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
		dest[i] = src[i], i++;
	if (i < n)
	{
		j = i;
		while (j < n)
			dest[j] = '\0', j++;
	}
	return (result);
}

/**
 * custom_cpy_str - Copy source string to destination.
 * @dest: The destination string.
 * @src: The source string.
 * Return: A pointer to the destination string.
 */

char *custom_cpy_str(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == NULL)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
