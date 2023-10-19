#include "shell.h"

/**
 * isCommandChainDelimiter - Check if the current character in the
 * buffer is a command chain delimiter.
 * @info: Data param.
 * @buf: Character buffer.
 * @p: & of the buffer burrent position.
 * checks if the character at the current position in the buffer is a
 * command chain delimiter ('|', '||', '&&', or ';').
 * If found, it updates the buffer and the command type accordingly.
 *
 * Return: 1 if it's a chain delimiter, or 0 otherwise.
 */
int isCommandChainDelimiter(info_t *info, char *buf, size_t *p)
{
	size_t _ptr = *p;

	if (buf[_ptr] == '|' && buf[_ptr + 1] == '|')
	{
		buf[_ptr] = '\0';
		_ptr++;
		info->command_type = COMMAND_OR;
	}
	else if (buf[_ptr] == '&' && buf[_ptr + 1] == '&')
	{
		buf[_ptr] = '\0';
		_ptr++;
		info->command_type = COMMAND_AND;
	}
	else if (buf[_ptr] == ';')
	{
		buf[_ptr] = '\0';
		info->command_type = COMMAND_CHAIN;
	}
	else
		return (0);

	*p = _ptr;
	return (1);
}
