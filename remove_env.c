#include "shell.h"

/**
 * remove_env - Remove an environment variable.
 * @info: data struct
 * @vars_: The string representing the environment variable.
 * Return: 1 on delete, 0 otherwise.
 */

int remove_env(info_t *info, char *vars_)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !vars_)
		return (0);

	while (node)
	{
		p = char_finder(node->str, vars_);
		if (p && *p == '=')
		{
			info->env_changed = delete_index_node(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

