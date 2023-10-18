#include "shell.h"

/**
 * check_interactive - Checks if the shell is in interactive mode
 * @info: Pointer to the info structure
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int check_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
