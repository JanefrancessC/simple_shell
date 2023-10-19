#include "shell.h"

/**
 * isExecutableCommand - Check if a file is an executable command.
 * @info: param struct | info.
 * @path: The file path.
 *
 * determines if the file at the given path is an executable command.
 *
 * Return: 1 if it's an executable command, 0 otherwise.
 */
int isExecutableCommand(info_t *info, char *path)
{
	struct stat fileStat;

	(void)info;
	if (!path || stat(path, &fileStat))
		return (0);

	if (S_ISREG(fileStat.st_mode))
	{
		return (1);
	}
	return (0);
}
