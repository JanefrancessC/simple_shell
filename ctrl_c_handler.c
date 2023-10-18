#include "shell.h"

/**
 * ctrl_c_handler - Blocks Ctrl-C.
 * @_indicator: The signal number.
 *
 * Return: Void.
 */
void ctrl_c_handler(__attribute__((unused))int _indicator) {
    custom_put_str("\n");
    custom_put_str("$ ");
    _putchar(BUFFER_FLUSH);
}
