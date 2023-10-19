#include "shell.h"

void checkCommandChain(info_t *info, char *buf,
		size_t *p, size_t i, size_t len)
{
	size_t _ptr = *p;

	if (info->command_type == COMMAND_AND)
	{
		if (info->status)
		{
			buf[i] = '\0';
			_ptr = len;
		}
	}
	if (info->command_type == COMMAND_OR)
	{
		if (!info->status)
		{
			buf[i] = '\0';
			_ptr = len;
		}
	}

	*p = _ptr;
}
