#include "shell.h"

/**
 * free_info - Frees the allocated memory and resources in the info_t struct.
 * @info: Pointer to the info_t struct.
 * @_vars_: True if freeing all fields.
 */
void free_info(info_t *info, int _vars_)
{
	_custom_free(info->argv);
	info->argv = NULL;
	info->path = NULL;

	if (_vars_)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		_custom_free(info->environ);
		info->environ = NULL;
		buf_free((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUFFER_FLUSH);
	}
}


/**
 * buf_free - Free pointer allocated memory.
 * @ptr: The address of the pointer to be freed.
 * Return: 1 on success or 0 otherwise.
 */
int buf_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
