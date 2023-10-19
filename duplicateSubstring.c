#include "shell.h"

/**
 * duplicateSubstring - Create new string by duplicating from a substring.
 * @sourceString: The source string.
 * @startIndex: Index begin.
 * @stopIndex: Index stop.
 * Return: A pointer to the new buffer containing the copied characters.
 */
char *duplicateSubstring(char *sourceString, int startIndex, int stopIndex)
{
	static char buffer[1024];
	int destIndex = 0, srcIndex = 0;

	for (srcIndex = startIndex, destIndex = 0; srcIndex < stopIndex; srcIndex++)
	{
		if (sourceString[srcIndex] != ':')
		{
			buffer[destIndex++] = sourceString[srcIndex];
		}
	}
	buffer[destIndex] = '\0';
	return (buffer);
}

