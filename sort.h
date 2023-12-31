#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void selection_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void quick_sort(int *array, size_t size);
void quicksort(int *array, int low, int high, size_t size);
int Lomuto_partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void swap_right(listint_t **list, listint_t *head, listint_t *tmp);
void swap_left(listint_t **list, listint_t *head, listint_t *tmp);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
#endif
