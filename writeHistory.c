#include "shell.h"

/**
 * writeHistory - Create a new history file.
 * @info: Data param.
 * Return: On success, 1, otherwise -1.
 */
int writeHistory(info_t *info)
{
	int fd;
	char *filename = read_hist_all(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);

	if (fd == -1)
		return (-1);

	for (node = info->history; node; node = node->next)
	{
		_putstr_fd(node->str, fd);
		_putchar_fd('\n', fd);
	}

	_putchar_fd(BUFFER_FLUSH, fd);
	close(fd);

	return (1);
}
