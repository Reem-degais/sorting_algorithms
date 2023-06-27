#include "sort.h"

/**
 * merge - Merge two sorted sub-arrays into a single sorted array
 * @array: The original array
 * @temp: The temporary array used for merging
 * @left_start: The starting index of the left sub-array
 * @left_end: The ending index of the left sub-array
 * @right_start: The starting index of the right sub-array
 * @right_end: The ending index of the right sub-array
 */
void merge(int *array, int *temp, size_t left_start, size_t left_end, size_t right_start, size_t right_end)
{
    size_t i = left_start;
    size_t j = right_start;
    size_t k = left_start;
	size_t x;

    printf("Merging...\n");
    printf("[left]: ");
    for (x = left_start; x <= left_end; x++)
    {
        printf("%d", array[x]);
        if (x != left_end)
            printf(", ");
    }
    printf("\n");
    printf("[right]: ");
    for (x = right_start; x <= right_end; x++)
    {
        printf("%d", array[x]);
        if (x != right_end)
            printf(", ");
    }
    printf("\n");

    while (i <= left_end && j <= right_end)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= left_end)
    {
        temp[k] = array[i];
        i++;
        k++;
    }

    while (j <= right_end)
    {
        temp[k] = array[j];
        j++;
        k++;
    }

    for (x = left_start; x <= right_end; x++)
    {
        array[x] = temp[x];
    }

    printf("[Done]: ");
    for (x = left_start; x <= right_end; x++)
    {
        printf("%d", array[x]);
        if (x != right_end)
            printf(", ");
    }
    printf("\n");
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
    {
        return;
    }

    mid = start + (end - start) / 2;
    merge_sort_helper(array, temp, start, mid);
    merge_sort_helper(array, temp, mid + 1, end);
    merge(array, temp, start, mid, mid + 1, end);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge sort algorithm
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
