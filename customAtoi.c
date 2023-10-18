#include "shell.h"

/**
 * customAtoi - converts a string to an integer
 * @str: the string to be converted
 *
 * Return: the converted integer, or 0 if no numbers in the string
 */
int customAtoi(char *str)
{
    int index = 0;
    int sign = 1;
    int result = 0;
    unsigned int number = 0;
    int digitFlag = 0;

    for (index = 0; str[index] != '\0' && digitFlag != 2; index++)
    {
        if (str[index] == '-')
            sign *= -1;

        if (str[index] >= '0' && str[index] <= '9')
        {
            digitFlag = 1;
            number *= 10;
            number += (str[index] - '0');
        }
        else if (digitFlag == 1)
        {
            digitFlag = 2;
        }
    }

    if (sign == -1)
        result = -number;
    else
        result = number;

    return result;
}
