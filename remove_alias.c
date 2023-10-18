#include "shell.h"

/**
 * remove_alias - Removes an alias with the provided string.
 * @info: dat astruct.
 * @str: The alias string to be removed.
 *
 * Return: returns 0 on success, 1 on error.
 */
int remove_alias(info_t *info, char *str)
{
	char *equal_sign, c;
	int result;

	equal_sign = custom_strchr(str, '=');
	if (!equal_sign)
		return (1);
	c = *equal_sign;
	*equal_sign = '\0';
	result = delete_index_node(&(info->alias),
			get_node_index(info->alias, starts_with_node(info->alias, str, -1)));
	*equal_sign = c;
	return (result);
}
