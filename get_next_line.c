#include "shell.h"

/**
 * get_next_line - Gets the next line of input from STDIN.
 * @info: Data struct.
 * @ptr: Address of the pointer to the buffer, preallocated or NULL.
 * @length: Size of the preallocated ptr buffer if not NULL.
 * Return: int | size of var s.
 */
int get_next_line(info_t *info, char **ptr, size_t *length)
{
	static char _buffer[READ_BUFFER_SIZE];
	static size_t i, _len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == _len)
		i = _len = 0;
	r = readBuffer(info, _buffer, &_len);
	if (r == -1 || (r == 0 && _len == 0))
		return (-1);
	c = custom_strchr(_buffer + i, '\n');
	k = c ? 1 + (unsigned int)(c - _buffer) : _len;
	new_p = custom_re_alloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		custom_strcat(new_p, _buffer + i, k - i);
	else
		custom_strncpy(new_p, _buffer + i, k - i + 1);

	s += k - i, i = k, p = new_p;
	if (length)
		*length = s;
	*ptr = p;
	return (s);
}
