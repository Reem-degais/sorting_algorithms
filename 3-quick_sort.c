#include "sort.h"


/**
 * Lomuto-partition - lomuto partition sorting scheme implementation.
 * @array: an array of integers.
 * @low: first array element.
 * @high: last array element.
 * @size: size of anarray.
 * Return: new  position.
 */
int Lomuto_partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	if (array[i] != array[high])
		print_array(array, size);
	return (i);
}

/**
 * quicksort - qucksort algorithm implementation.
 * @array: an array of integers.
 * @low: first array element.
 * @high: last array element.
 * @size: size of a array.
 * Return: nothing.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = Lomuto_partition(array, low, high, size);
		quicksort(array, low, p - 1, size);
		quicksort(array, p + 1, high, size);
	}
}


/**
 * quick_sort - sorts an array using the Quick sort algorithm.
 * @array: an array of integers.
 * @size: size of an array.
 * Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
