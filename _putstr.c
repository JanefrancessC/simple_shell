#include "shell.h"

/**
 * _putstr - writes an input string to standard IO/err.
 * @str: the string to be printed.
 */
void _putstr(char *str)
{
    int i = 0;

    if (!str)
        return;
    while (str[i] != '\0')
    {
        _put_char(str[i]);
        i++;
    }
}
