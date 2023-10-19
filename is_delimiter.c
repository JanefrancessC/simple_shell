#include "shell.h"

/**
 * is_delimiter - Checks if a character is a delimiter
 * @character: The character to check
 * @delimiters: The delimiter string
 * Return: 1 if true, 0 if false
 */

int is_delimiter(char character, char *delimiters)
{
	while (*delimiters)
	{
		if (*delimiters++ == character)
		{
			return (1);
		}
	}
	return (0);
}
