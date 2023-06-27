#include "sort.h"

/**
 * print_subarray - Print a subarray of the given array
 * @array: The array to be printed
 * @start: The starting index of the subarray
 * @end: The ending index of the subarray
 */
void print_subarray(int *array, size_t start, size_t end)
{
	size_t i;

	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
	}
	printf("\n");
}

/**
 * merge - Merge two sorted sub-arrays into a single sorted array
 * @array: The original array
 * @temp: The temporary array used for merging
 * @left_start: The starting index of the left sub-array
 * @left_end: The ending index of the left sub-array
 * @right_start: The starting index of the right sub-array
 * @right_end: The ending index of the right sub-array
 */
void merge(int *array, int *temp, size_t left_start, size_t left_end,
size_t right_start, size_t right_end)
{
	size_t i = left_start;
	size_t j = right_start;
	size_t k = left_start;
	size_t x;

	if (!array || *temp || !left_end || !right_end)
		return;
	printf("Merging...\n");
	printf("[left]: ");
	print_subarray(array, left_start, left_end);
	printf("[right]: ");
	print_subarray(array, right_start, right_end);
	while (i <= left_end && j <= right_end)
	{
		if (array[i] <= array[j])
			temp[k] = array[i++];
		else
			temp[k] = array[j++];
		k++;
	}
	while (i <= left_end)
		temp[k++] = array[i++];
	while (j <= right_end)
		temp[k++] = array[j++];
	for (x = left_start; x <= right_end; x++)
		array[x] = temp[x];
	printf("[Done]: ");
	print_subarray(array, left_start, right_end);
}

/**
 * merge_sort_helper - Recursive helper function for merge sort
 * @array: The array to be sorted
 * @temp: The temporary array used for merging
 * @start: The starting index of the current sub-array
 * @end: The ending index of the current sub-array
 */
void merge_sort_helper(int *array, int *temp, size_t start, size_t end)
{
	size_t mid;

	if (start >= end)
		return;
	mid = start + (end - start) / 2;
	merge_sort_helper(array, temp, start, mid);
	merge_sort_helper(array, temp, mid + 1, end);
	merge(array, temp, start, mid, mid + 1, end);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp = malloc(size * sizeof(int));

	if (temp == NULL)
	{
		printf("Memory allocation failed!\n");
		return;
	}
	merge_sort_helper(array, temp, 0, size - 1);
	free(temp);
}
