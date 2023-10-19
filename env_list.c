#include "shell.h"

/**
 * env_list - Array list of the environment variables.
 * @info: Data struct
 * Return: Return 0 for success
 */

char **env_list(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		char **new_environ = list_to_strings(info->env);
		if (new_environ)
		{
			free(info->environ);
			info->environ = new_environ;
			info->env_changed = 0;
		}
	}

	return (info->environ);
}

