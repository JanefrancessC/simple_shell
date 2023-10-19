#include "shell.h"

/**
 * linked_list_length - Calculates the list's length.
 * @_head: First node pointer.
 * Calculates the list's length.
 * Return: The list sixe.
 */

size_t linked_list_length(const list_t *_head)
{
	size_t i = 0;

	while (_head)
	{
		_head = _head->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: First node pointer
 * returns an array of strings of the list->str
 * Return: list of string array
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = linked_list_length(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = custom_cpy_str(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - To print the elements of a list
 * @_head: First node pointer
 * To print the elements of a list
 * Return: size of list
 */
size_t print_list(const list_t *_head)
{
	size_t i = 0;

	while (_head)
	{
		custom_put_str(custom_itoa(_head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		custom_put_str(_head->str ? _head->str : "(nil)");
		custom_put_str("\n");
		_head = _head->next;
		i++;
	}
	return (i);
}
