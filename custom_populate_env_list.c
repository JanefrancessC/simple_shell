#include "shell.h"

/**
 * custom_populate_env_list - populates the custom environment linked list
 * @info: data struct
 * Return: returns 0
 */
int custom_populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
