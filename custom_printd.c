#include "shell.h"

/**
 * custom_printd - prints an integer in base 10 to a file descriptor.
 * @numb10: the number input.
 * @fd: the file descriptor to be written to.
 * Return: the printed number count.
 */
int custom_printd(int numb10, int fd)
{
	int (*custom_putchar)(char) = _putchar;
	int i;
	int counter = 0;
	unsigned int abslt, curr;

	if (fd == STDERR_FILENO)
		custom_putchar = _put_char;
	if (numb10 < 0)
	{
		abslt = -numb10;
		custom_putchar('-');
		counter++;
	}
	else
		abslt = numb10;
	curr = abslt;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (abslt / i)
		{
			custom_putchar('0' + curr / i);
			counter++;
		}
		curr %= i;
	}
	custom_putchar('0' + curr);
	counter++;

	return (counter);
}
