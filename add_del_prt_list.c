#include "shell.h"

/**
 * delete_index_node - deletes the specified indexed node.
 * @head_ptr: &(*headnote).
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_index_node(list_t **head_ptr, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head_ptr || !*head_ptr)
		return (0);

	if (!index)
	{
		node = *head_ptr;
		*head_ptr = (*head_ptr)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head_ptr;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: &(*headnote).
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	memory_set((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = custom_dup_str(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - To display string elemnts of a list
 * @_head_: First node pointer.
 * Return: List size.
 */
size_t print_list_str(const list_t *_head_)
{
	size_t i = 0;

	while (_head_)
	{
		custom_put_str(_head_->str ? _head_->str : "(nil)");
		custom_put_str("\n");
		_head_ = _head_->next;
		i++;
	}
	return (i);
}
