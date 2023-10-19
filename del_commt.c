#include "shell.h"

/**
 * del_commt - Replace the first '#' with '\0' in the string.
 * @buffer: The address of the string to modify.
 * Return: Always 0.
 */
void del_commt(char *buffer)
{
	int i = 0;

	while (buffer[i] != '\0')
	{
		if (buffer[i] == '#' && (i == 0 || buffer[i - 1] == ' '))
		{
			buffer[i] = '\0';
			break;
		}
		i++;
	}
}
