#include "shell.h"

/**
 * print_single_alias - Print a single alias to an output
 * @node: pointer to node in a linked list containing alias strings
 * Return: 0 on success and 1 if node is NULL
 */

int print_single_alias(list_t *node)
{
	char *equal_sign = NULL;
	char *alias = NULL;

	if (node)
	{
		equal_sign = custom_strchr(node->str, '=');
		for (alias = node->str; alias <= equal_sign; alias++)
		{
			_putchar(*alias);
		}
		/*_putchar('\'');*/
		_putchar('\\');
		custom_put_str(equal_sign + 1);
		custom_put_str("'\n");
		return (0);
	}
	return (1);
}
