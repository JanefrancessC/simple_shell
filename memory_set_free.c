#include "shell.h"

/**
 * *memory_set - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: Pointer to the memory area
 */
char *memory_set(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}


/**
 * _custom_free - To free memory alllocated to sting ointers.
 * @strpp: pointer to string pointer .
 */
void _custom_free(char **strpp)
{
	char **a = strpp;

	if (!strpp)
		return;
	while (*strpp)
		free(*strpp++);
	free(a);
}
