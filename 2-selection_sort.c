#include "sort.h"

/**
 * selection_sort - sorts an array using the Selection sort algorithm.
 * @size: size of an array.
 * Return: nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min, swap;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap = array[i];
			array[i] = array[min];
			array[min] = swap;
			print_array(array, size);
		}
	}
}
