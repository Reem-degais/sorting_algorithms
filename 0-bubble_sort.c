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

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1] && array[j + 1])
			{
			swap = array[j];
			array[j] = array[j + 1];
			array[index + 1] = swap;
			print_array(array, size);
			}
		}
}
