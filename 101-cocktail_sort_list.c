#include "sort.h"

/**
 * swap_right - swaps nodes from left to right
 * @list: pointer to list
 * @head: pointer to head node
 * @tmp: tmp pointer
 * Return: nothing
 */
void swap_right(listint_t **list, listint_t *head, listint_t *tmp)
{
	if (head->prev)
		head->prev->next = tmp;
	else
		*list = tmp;
	if (tmp->next)
		tmp->next->prev = head;
	head->next = tmp->next;
	tmp->prev = head->prev;
	tmp->next = head;
	head->prev = tmp;
	print_list(*list);

}

/**
 * swap_left - swaps nodes from right to left
 * @list: pointer to list
 * @head: pointer to head node
 * @tmp: tmp pointer
 * Return: nothing
 */
void swap_left(listint_t **list, listint_t *head, listint_t *tmp)
{
	tmp = head->prev;
	tmp->next->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	else
		*list = tmp->next;
	tmp->prev = tmp->next;
	tmp->next = tmp->next->next;
	tmp->prev->next = tmp;
	if (tmp->next)
		tmp->next->prev = tmp;
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts doubly list using Cocktail shaker sort algorithm
 * @list: doubly linked list.
 * Return: nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *tmp;
	int flag = 1;

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	if (list)
	{
		head = *list;
		while (flag != 0)
		{
			flag = 0;
			while (head->next)
			{
				if (head->n > head->next->n)
				{
					tmp = head->next;
					swap_right(list, head, tmp);
					flag = 1;
				}
				else
					head = head->next;
			}
			if (flag == 0)
				break;
			flag = 0;
			while (head->prev)
			{
				if (head->prev->n > head->n)
				{
					swap_left(list, head, tmp);
					flag = 1;
				}
				else
					head = head->prev;
			}

		}
	}
}
