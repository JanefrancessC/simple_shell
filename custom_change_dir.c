#include "shell.h"

/**
 * _custom_change_directory - Changes the directory.
 * @info: data struct
 * Return:  0 for success
 */
int _custom_change_directory(info_t *info)
{
	char *current_dir, *new_dir, buffer[1024];
	int cd_return;

	current_dir = getcwd(buffer, 1024);
	if (!current_dir)
		custom_put_str("TODO: Handle getcwd failure\n");
	if (!info->argv[1])
	{
		new_dir = custom_getenv(info, "HOME=");
		if (!new_dir)
			cd_return =	chdir((new_dir = custom_getenv(info, "PWD=")) ? new_dir : "/");
		else
			cd_return = chdir(new_dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!custom_getenv(info, "OLDPWD="))
		{
			custom_put_str(current_dir), _putchar('\n');
			return (1);
		}
		custom_put_str(custom_getenv(info, "OLDPWD=")), _putchar('\n');
		cd_return = chdir((new_dir = custom_getenv(info, "OLDPWD=")) ? new_dir : "/");
	}
	else
		cd_return = chdir(info->argv[1]);
	if (cd_return == -1)
	{
		err_msg(info, "Unable to change directory to ");
		_putstr(info->argv[1]), _put_char('\n');
	}
	else
	{
		add_env(info, "OLDPWD", custom_getenv(info, "PWD="));
		add_env(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
