#include "shell.h"

/**
 * switch_string - Replace a string with a new one.
 * @str1: Address of the old string.
 * @str2: The new string.
 *
 * replace the old string with a new one and frees the old string.
 *
 * Return: 1 if replaced, 0 otherwise.
 */
int switch_string(char **str1, char *str2)
{
	free(*str1);
	*str1 = str2;
	return (1);
}
