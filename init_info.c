#include "shell.h"

/**
 * init_info - To initializes the info_t struct fields.
 * @info: Pointer to the info_t struct.
 */

void init_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

