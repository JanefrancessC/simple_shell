#include "shell.h"

/**
 * alias_builtin - Emulates the behavior of the alias
 *	builtin command (man alias).
 * @info: data struct.
 *
 * Return: returns 0.
 */
int alias_builtin(info_t *info)
{
	int i = 0;
	char *equal_sign = NULL;
	list_t *alias_node = NULL;

	if (info->argc == 1)
	{
		alias_node = info->alias;
		while (alias_node)
		{
			print_single_alias(alias_node);
			alias_node = alias_node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		equal_sign = custom_strchr(info->argv[i], '=');
		if (equal_sign)
			create_alias(info, info->argv[i]);
		else
			print_single_alias(starts_with_node(info->alias, info->argv[i], '='));
	}

	return (0);
}
