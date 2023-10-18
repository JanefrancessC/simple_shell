#include "shell.h"

/**
 * _custom_exit - Exits the shell with a given status.
 * @info: data struct
 * Return: 0 if info->argv[0] is not "exit," -2 if exit argument is provided.
 */
int _custom_exit(info_t *info)
{
	int exit_status;

	if (info->argv[1])
	{
		exit_status = custom_atoi(info->argv[1]);
		if (exit_status == -1)
		{
			info->status = 2;
			err_msg(info, "Number unknown: ");
			_putstr(info->argv[1]), _put_char('\n');
			return (1);
		}
		info->err_num = exit_status;
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
