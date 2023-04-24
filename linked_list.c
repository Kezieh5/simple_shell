#include "shell.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the head of the list
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	for (; h != NULL; i++)
	{
		if (h->str != NULL)
			_puts(STDOUT_FILENO, h->str);
		else
			_puts(STDOUT_FILENO, "(nil)");

		h = h->next;
	}

	return (i);
}
