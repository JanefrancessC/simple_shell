#include "shell.h"

/**
 * _custom_help - Displays help information.
 * @info: Data struct
 * Return: 0 for success
 */

int _custom_help(info_t *info)
{
	char **args;

	args = info->argv;
	custom_put_str("Help function is not yet implemented.\n");
	if (0)
		custom_put_str(*args);
	return (0);
}
