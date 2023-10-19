#include "shell.h"

/**
 * variables_replace - Replace environment variables in the split string.
 * @info: Data param.
 * Return: 1 if any variable was replaced, 0 otherwise.
 */
int variables_replace(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		if (!_strcmp(info->argv[i], "$?"))
		{
			switch_string(&(info->argv[i]),
					custom_dup_str(custom_itoa(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			switch_string(&(info->argv[i]),
					custom_dup_str(custom_itoa(getpid(), 10, 0)));
			continue;
		}
		node = starts_with_node(info->env, &info->argv[i][1], '=');
		if (node)
		{
			switch_string(&(info->argv[i]),
					custom_dup_str(custom_strchr(node->str, '=') + 1));
			continue;
		}
		switch_string(&info->argv[i], custom_dup_str(""));
	}
	return (0);
}
