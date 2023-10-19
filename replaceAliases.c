#include "shell.h"

/**
 * replaceAliases - This will reconfigure an exisiting alias
 * @info: Data param.
 * Return: 1 if any alias was replaced, 0 otherwise.
 */
int replaceAliases(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = starts_with_node(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = custom_strchr(node->str, '=');
		if (!p)
			return (0);
		p = custom_dup_str(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}
