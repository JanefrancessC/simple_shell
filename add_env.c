#include "shell.h"

/**
 * add_env - set a new environment variable.
 * @info: data struct.
 * @vars_: The string representing the environment variable property.
 * @value: The string representing the environment variable value.
 * Return: return 0.
 */
int add_env(info_t *info, char *vars_, char *value)
{
	char *buffer = NULL, *p;
	list_t *node;

	if (!vars_ || !value)
		return (0);

	buffer = malloc(_strlen(vars_) + _strlen(value) + 2);
	if (!buffer)
		return (1);
	custom_cpy_str(buffer, vars_);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	node = info->env;
	while (node)
	{
		p = char_finder(node->str, vars_);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buffer;
			info->env_changed = 1;
			free(buffer);
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buffer, 0);
	free(buffer);
	info->env_changed = 1;
	return (0);
}
