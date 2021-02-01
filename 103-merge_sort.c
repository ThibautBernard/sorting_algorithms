#include "sort.h"

/**
 * merge - Merges 2 sorted arrays
 * @ary: The array to be sorted
 * @aux_ary: The Auxiliary array where the magic happens
 * @start: The starting index of the array
 * @middle: The index where we split the array
 * @end: The ending index of the array
 *
 * Return: Nothing
 */

void merge(int *ary, int *aux_ary, size_t start, size_t middle, size_t end)
{
	size_t k = start;       /* start of sorted array */
	size_t i = start;       /* start of left array */
	size_t j = middle + 1;  /* start of right array */

	printf("Merging...\n");
	printf("[left]: ");
	print_array(aux_ary + start, middle - start + 1);
	printf("[right]: ");
	print_array(aux_ary + (middle + 1), end - middle);

	while (i <= middle && j <= end)
	{
		if (aux_ary[i] <= aux_ary[j])
		{
			ary[k] = aux_ary[i];
			i++;
		}
		else
		{
			ary[k] = aux_ary[j];
			j++;
		}
		k++;
	}
	while (i <= middle)
	{
		ary[k] = aux_ary[i];
		i++;
		k++;
	}
	while (j <= end)
	{
		ary[k] = aux_ary[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(ary + start, end - start + 1);
}

/**
 * merge_sort_helper - helper function for  Merge Sort Algorithm
 * @ary: The array to be sorted
 * @aux_ary: The Auxiliary array where the magic happens
 * @start: The starting index of the array
 * @end: The ending index of the array
 *
 * Return: Nothing
 */

void merge_sort_helper(int *ary, int *aux_ary, size_t start, size_t end)
{
	size_t middle = 0;

	if (start < end)
	{

		middle = (start + end) / 2;
		if ((start + end) % 2 == 0)
			middle -= 1;

		merge_sort_helper(aux_ary, ary, start, middle);
		merge_sort_helper(aux_ary, ary, middle + 1, end);
		merge(ary, aux_ary, start, middle, end);

	}
}

/**
 * merge_sort - Sort array using the Merge Sort Algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */

void merge_sort(int *array, size_t size)
{
	int *aux_array;
	size_t i;

	if (!array)
		return;

	aux_array = malloc(sizeof(int) * size);
	if (aux_array == NULL)
		return;

	for (i = 0; i < size; i++)
		aux_array[i] = array[i];

	merge_sort_helper(array, aux_array, 0, size - 1);

	free(aux_array);
}
