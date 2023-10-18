#include "shell.h"

/**
 * _is_alpha - checks if a character is alphabetic
 * @c: The character to check
 *
 * Return: 1 if 'c' is an alphabetic character, 0 otherwise
 */
int _is_alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
