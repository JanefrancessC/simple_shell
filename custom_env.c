#include "shell.h"

/**
 * custom_env - displays the  environment variables
 * @info: data struct.
 * Return: returns 0.
 */
int custom_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
