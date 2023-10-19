#include "shell.h"

/**
 * readBuffer - To read a buffer.
 * @info: data struct.
 * @buf: Buffer.
 * @i: buffer size.
 * Return: the size read.
 */

ssize_t readBuffer(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
	{
		return (0);
	}
	r = read(info->readfd, buf, READ_BUFFER_SIZE);
	if (r >= 0)
	{
		*i = r;
	}
	return (r);
}
