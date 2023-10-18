#include "shell.h"

/**
 * custom_re_alloc - replicates the builtin realloc.
 * @ptr: pointer to inital  memory block.
 * @old_size: byte size of initial memory.
 * @new_size: size of the newly allocated block.
 * Return: pointer allocated memory bloack.
 */
void *custom_re_alloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
