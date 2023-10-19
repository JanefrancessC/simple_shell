#include "shell.h"

/**
 * getInput - reads a line.
 * @info: data param struct.
 * Return: The count of bytes read.
 */
ssize_t getInput(info_t *info)
{
	static char *buf; /* The ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUFFER_FLUSH);
	r = bufferInput(info, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i, p = buf + i;

		checkCommandChain(info, buf, &j, i, len);
		while (j < len)
		{
			if (isCommandChainDelimiter(info, buf, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0, info->command_type = COMMAND_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}
	*buf_p = buf;
	return (r);
}
