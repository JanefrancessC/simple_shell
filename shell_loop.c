#include "shell.h"

/**
 * hsh - The main shell which loops to listen for commands
 * @info: struct param
 * @av: argv argument vector
 * The main shell which loops to listen for commands
 * Return: 0 if successful, 1 if error is ecountered
 */
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		init_info(info);
		if (check_interactive(info))
			custom_put_str("$ ");
		_put_char(BUFFER_FLUSH);
		r = getInput(info);
		if (r != -1)
		{
			fill_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				_find_cmd_(info);
		}
		else if (check_interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	writeHistory(info);
	free_info(info, 1);
	if (!check_interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - finds system's built-in commands
 * @info: struct param
 * It searches for the command in
 * Return: -1 if a builtin command is not found, 0 if successfully executed,
 * 1 if found but not successful and -2 if builtin signals exit()
 */
int find_builtin(info_t *info)
{
	int i, ret_builtin = -1;
	builtin_table builtintbl[] = {
		{"exit", _custom_exit},
		{"env", custom_env},
		{"help", _custom_help},
		{"history", display_history},
		{"setenv", custom_setenv},
		{"unsetenv", custom_unsetenv},
		{"cd", _custom_change_directory},
		{"alias", alias_builtin},
		{NULL, NULL}
	};
	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			ret_builtin = builtintbl[i].func(info);
			break;
		}
	return (ret_builtin);
}
