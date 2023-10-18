#include "shell.h"

/**
 * del_commt - Replace the first '#' with '\0' in the string.
 * @buffer: The address of the string to modify.
 *
 * This function scans the string and replaces the first instance of '#' with
 * '\0'. It also checks if the '#' is preceded by a space character. The goal is
 * to remove comments from the string.
 *
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
