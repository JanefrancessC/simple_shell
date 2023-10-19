#include "shell.h"

/**
 * read_hist_all - Retrieve history list
 * @info: Data param
 * Return: String containing the history file paths.
 */
char *read_hist_all(info_t *info)
{
	char *homeDir, *historyPath;

	homeDir = custom_getenv(info, "HOME=");
	if (!homeDir)
	{
		return (NULL);
	}

	historyPath = malloc(sizeof(char) *
			(_strlen(homeDir) + _strlen(HISTORY_FILE) + 2));
	if (!historyPath)
		return (NULL);

	historyPath[0] = 0;
	custom_cpy_str(historyPath, homeDir);
	_strcat(historyPath, "/");
	_strcat(historyPath, HISTORY_FILE);

	return (historyPath);
}

