#include "shell.h"

/**
 * custom_atoi - converts a character array/ string to an integer
 * @s: the string to be converted
 * Return: the converted integer, or 0 if no arg was passed or -1 for error
 */

int custom_atoi(char *s)
{
	unsigned long int result = 0;
	int i = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
