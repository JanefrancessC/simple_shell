#include "shell.h"

/**
 * create_alias - Creates an alias from the provided string.
 * @info: Parameter structure.
 * @str: The alias string to be created.
 *
 * Return: Always returns 0 on success, 1 on error.
 */
int create_alias(info_t *info, char *str)
{
    char *equal_sign;

    equal_sign = custom_strchr(str, '=');
    if (!equal_sign)
    {
        return (1);
    }
    if (!*++equal_sign)
        return remove_alias(info, str);

    remove_alias(info, str);
    return (add_node_end(&(info->alias), str, 0) == NULL);
}
