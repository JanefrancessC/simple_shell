#include "shell.h"

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
