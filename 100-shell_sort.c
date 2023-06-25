#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell sort algorithm
 *              with the Knuth sequence.
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Return: void.
 */
void	shell_sort(int array[], size_t size)
{
	size_t	interval = 1;
	size_t	i, j;

	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}
	while (interval > 0)
	{
		for (i = interval; i < size; ++i)
		{
			int temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		for (i = 0; i < size; ++i)
		{
			if (i > 0)
				printf(", ");
			printf("%d ", array[i]);
		}
		printf("\n");
		interval = (interval - 1) / 3;
	}
}
