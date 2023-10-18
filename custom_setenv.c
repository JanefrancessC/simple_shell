#include "shell.h"

/**
 * custom_setenv - defines an environment variable and assign a value to it
 * @info: data struct
 *  Return: Returns 0 on success, 1 on failure.
 */
int custom_setenv(info_t *info)
{
    if (info->argc != 3)
    {
        _putstr("Review the number of arguments entered\n");
        return (1);
    }
    if (add_env(info, info->argv[1], info->argv[2]))
        return (0);
    return (1);
}
