#include "shell.h"

/**
 * _put_char - writes a character
 * @c: The character to be printed.
 * Return: returns 1 if successful, otherwise -1.
 */
int _put_char(char c)
{
    static int i;
    static char _buffer[BUFFER_SIZE_SET];

    if (c == BUFFER_FLUSH || i >= BUFFER_SIZE_SET)
    {
        write(2, _buffer, i);
        i = 0;
    }
    if (c != BUFFER_FLUSH)
        _buffer[i++] = c;
    return (1);
}
