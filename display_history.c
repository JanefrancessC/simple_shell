#include "shell.h"

/**
 * display_history - Displays the command history list with line numbers.
 * @info: data struct
 *
 * Return: returns 0
 */
int display_history(info_t *info)
{
	print_list(info->history);
	return (0);
}
