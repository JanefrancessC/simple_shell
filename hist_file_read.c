#include "shell.h"

/**
 * hist_file_read - Get history list from file.
 * @info: Data param.
 * Return: The count of history list or 0, on failure.
 */
int hist_file_read(info_t *info)
{
	struct stat fileStat;
	ssize_t fd, readLen, fileSize = 0;
	char *buf = NULL, *filename = read_hist_all(info);
	int i, last = 0, lineCount = 0;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &fileStat))
		fileSize = fileStat.st_size;
	if (fileSize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fileSize + 1));
	if (!buf)
		return (0);
	readLen = read(fd, buf, fileSize);
	buf[fileSize] = 0;
	if (readLen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fileSize; i++)
	{
		if (buf[i] == '\n')
		{
			buf[i] = 0, add_history_list(info, buf + last, lineCount++);
			last = i + 1;
		}
	}
	if (last != i)
		add_history_list(info, buf + last, lineCount++);
	free(buf);
	info->histcount = lineCount;
	while (info->histcount-- >= HIST_MAX)
		delete_index_node(&(info->history), 0);
	sort_hist(info);
	return (info->histcount);
}
