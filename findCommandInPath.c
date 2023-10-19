#include "shell.h"

/**
 * findCommandInPath - Find the full path of a command in the PATH string.
 * @info: The information struct.
 * @pathString: The PATH string.
 * @command: The command to find.
 * Return: The full path of the command if found, or NULL if not found.
 */
char *findCommandInPath(info_t *info, char *pathString, char *command)
{
	int currentIndex = 0, currentPos = 0;
	char *path;

	if (!pathString)
		return (NULL);
	if (_strlen(command) > 2 && char_finder(command, "./"))
	{
		if (isExecutableCommand(info, command))
			return (command);
	}
	while (1)
	{
		if (!pathString[currentIndex] || pathString[currentIndex] == ':')
		{
			path = duplicateSubstring(pathString, currentPos, currentIndex);
			if (!*path)
				_strcat(path, command);
			else
			{
				_strcat(path, "/");
				_strcat(path, command);
			}
			if (isExecutableCommand(info, path))
				return (path);
			if (!pathString[currentIndex])
				break;
			currentPos = currentIndex;
		}
		currentIndex++;
	}
	return (NULL);
}

/**
 * _find_cmd_ - finds a command in PATH
 * @info: the parameter & return info struct
 * Return: void
 */
void _find_cmd_(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delimiter(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = findCommandInPath(info, custom_getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((check_interactive(info) || custom_getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && isExecutableCommand(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			err_msg(info, "not found\n");
		}
	}
}

