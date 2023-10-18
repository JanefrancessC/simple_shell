#include "shell.h"

/**
 * custom_put_str - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void custom_put_str(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * custom_dup_str - duplicates a string
 * @str: the string to duplicate
 * Return: pointer to the duplicated string
 */

char *custom_dup_str(const char *str)
{
	int length = 0;
	char *duplicate;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	duplicate = malloc(sizeof(char) * (length + 1));
	if (!duplicate)
		return (NULL);
	for (length++; length--;)
		duplicate[length] = *--str;
	return (duplicate);
}


/**
 * _putchar - Write a character to stdout.
 * @c: Character to be written.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	static int index;
	static char buffer[BUFFER_SIZE_SET];

	if (c == BUFFER_FLUSH || index >= BUFFER_SIZE_SET)
	{
		write(1, buffer, index);
		index = 0;
	}
	if (c != BUFFER_FLUSH)
		buffer[index++] = c;
	return (1);
}
