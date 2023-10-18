#include "shell.h"

/**
 * add_history_list - To add an entry to history.
 * @info: Data param.
 * @buf: Buffer.
 * @lineCount: The history line count.
 * Return: 0 for success.
 */

int add_history_list(info_t *info, char *buf, int linecount) {
    list_t *node = NULL;

    if (info->history) {
        node = info->history;
    }

    add_node_end(&node, buf, linecount);

    if (!info->history) {
        info->history = node;
    }

    return (0);
}
