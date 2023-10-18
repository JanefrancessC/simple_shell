#include "shell.h"

/**
 * _putchar_fd - writes a character to a specified file descriptor.
 * @c: The character to be printed.
 * @fd: The file descriptor to write to.
 * Return: returns 1 if successful, otherwise -1.
 */

int _putchar_fd(char c, int fd)
{
    static int i;
    static char _buffer[BUFFER_SIZE_SET];

    if (c == BUFFER_FLUSH || i >= BUFFER_SIZE_SET)
    {
        write(fd, _buffer, i);
        i = 0;
    }
    if (c != BUFFER_FLUSH)
        _buffer[i++] = c;
    return (1);
}
