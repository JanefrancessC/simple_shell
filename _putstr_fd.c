#include "shell.h"

/**
 * _putstr_fd - writes an input string to a specified file descriptor.
 * @str: the string to be printed.
 * @fd: the file descriptor to write to.
 * Return: the number of characters written to the FD
 */
int _putstr_fd(char *str, int fd)
{
    int i = 0;

    if (!str)
        return (0);
    while (*str)
        i += _putchar_fd(*str++, fd);
    return (i);
}
