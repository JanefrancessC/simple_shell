#include "shell.h"

/**
 * custom_strchr - find a character in a haystack of strings.
 * @s: The string to be searched.
 * @c: The character to find.
 *
 * Return: A pointer to the first occurrence of the character in the string.
 * If the character is not found, it returns NULL.
 */
char *custom_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (s);
        s++;
    }
    return (NULL);
}
