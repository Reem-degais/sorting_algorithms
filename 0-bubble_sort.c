#include "sort.h"

/**
 * bubble_sort - sorts an array of integrs using the Bubble sort algorithm.
 * @array: an array of integers.
 * @size: the size of an array.
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, swap = 0;

	if (!array || size < 2)
		return;
	for (i = 0; i < (size - 1); i++)
		for (j = 1; j < size; j++)
		{
			if (array[j] < array[j - 1])
			{
			swap = array[j];
			array[j] = array[j - 1];
			array[j - 1] = swap;
			print_array(array, size);
			}
		}
}
