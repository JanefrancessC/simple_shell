#include "shell.h"

/**
 * err_msg - displays error message notifications.
 * @info: data param.
 * @str: the error message
 */

void err_msg(info_t *info, char *str)
{
	_putstr(info->fname);
	_putstr(": ");
	custom_printd(info->line_count, STDERR_FILENO);
	_putstr(": ");
	_putstr(info->argv[0]);
	_putstr(": ");
	_putstr(str);
}
