#include "shell.h"

/**
 * sort_hist - To resort the history list.
 * @info: data param.
 * Return: count of history.
 */
int sort_hist(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}

	return (info->histcount = i);
}
