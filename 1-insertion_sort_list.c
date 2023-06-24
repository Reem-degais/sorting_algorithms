#include "sort.h"

/**
 * insertion_sort_list - sorts a linked list using Insertion sort algorithm.
 * @list: doubly linked list.
 * Return: nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *new, *node1, *node2;

	if (!list || !(*list)->next)
		return;

	node1 = *list;
	node2 = (*list)->next;
	while (node2)
	{
		new = node2->next;
		while (node1 && node1->n > node2->n)
		{
			if (node1->prev)
				node1->prev->next = node2;
			else
				*list = node2;
			if (node2->next)
				node2->next->prev = node1;
			tmp = node2->next;
			node2->next = node1;
			node2->prev = node1->prev;
			node1->next = tmp;
			node1->prev = node2;
			print_list(*list);

			node1 = node2->prev;
		}
		node2 = new;
		if (node2)
			node1 = node2->prev; }
}
