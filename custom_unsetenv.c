#include "shell.h"

/**
 * custom_unsetenv - Remove a custom environment variable
 * @info: data struct
 *  Return: Returns 0 on success, 1 on failure.
 */
int custom_unsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_putstr("Few arguments entered.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
	{
		remove_env(info, info->argv[i]);
	}
	return (0);
}
