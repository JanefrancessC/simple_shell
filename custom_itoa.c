#include "shell.h"

/**
 * custom_itoa - coverts the integer n into a character string
 * @n: the integer to be converted.
 * @b: the number base
 * @f: the args
 *
 * Return: string
 */
char *custom_itoa(long int n, int b, int f)
{
    char sign = 0;
    char *ptr;
    static char *arr;
    static char buffer[50];
    unsigned long num = n;

    if (!(f & UNSIGNED_CONV) && n < 0)
    {
        num = -n, sign = '-';
    }
    arr = f & CASE_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = arr[num % b];
        num /= b;
    } while (num != 0);

    if (sign)
        *--ptr = sign;
    return (ptr);
}
