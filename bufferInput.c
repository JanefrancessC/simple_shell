#include "shell.h"

/**
 * bufferInput - Reads and buffers chained commands.
 * @info: Parameter struct.
 * @buffer_: Address of buffer.
 * @len: Address of length variable.
 * Return: counts of bytes read.
 */
ssize_t bufferInput(info_t *info, char **buffer_, size_t *len) {
    ssize_t r = 0;
    size_t len_ptr = 0;

    if (!*len) 
    {
        free(*buffer_), *buffer_ = NULL;
        signal(SIGINT, ctrl_c_handler);
        #if USE_GETLINE
        r = getline(buffer_, &len_ptr, stdin);
        #else
        r = get_next_line(info, buffer_, &len_ptr);
        #endif
        if (r > 0)
        {
            if ((*buffer_)[r - 1] == '\n') 
            {
                (*buffer_)[r - 1] = '\0'; 
                r--;
            }
            info->linecount_flag = 1;
            del_commt(*buffer_);
            add_history_list(info, *buffer_, info->histcount++);
           
            *len = r;
            info->cmd_buf = buffer_;
        }
    }
    return (r);
}
