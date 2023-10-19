#include "shell.h"


/**
 * custom_getenv - Retrieve the value of an environment variable.
 * @info: data struct
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *custom_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *value;

	while (node)
	{
		value = char_finder(node->str, name);
		if (value && *value)
		{
			return (value);
		}
		node = node->next;
	}
	return (NULL);
}
