#include "shell.h"

/**
 * fill_info - Fills the info_t struct with data.
 * @info: Pointer to the info_t struct.
 * @argv_: Argument vector.
 */
void fill_info(info_t *info, char **argv_)
{
	int i = 0;

	info->fname = argv_[0];
	if (info->arg)
	{
		info->argv = tokenize_(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = custom_dup_str(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
		{
			/*Count the number of arguments.*/
		}
		info->argc = i;

		replaceAliases(info);
		variables_replace(info);
	}
}

