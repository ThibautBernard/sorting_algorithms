#include "sort.h"

/**
 * partition - function that check value in array with the pivot value
 * and swap places if needed
 * @array: the array
 * @low: the beginning of the array to start searching
 * @high: the end of the array
 * @size_array: the length of the full array (only for print_array)
 * Return: the place of the end or start of the next partition of the array
 */
int partition(int *array, int low, int high, int size_array)
{
	int pivot = array[high], tmp = 0;
	int i = low, j;
	int swap = 0;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (array[i] != array[j])
				swap = 1;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (swap)
				print_array(array, size_array);
			swap = 0;
			i++;
		}
	}
	if (array[i] != array[high])
		swap = 1;
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;
	if (swap)
		print_array(array, size_array);
	return (i);
}
/**
 * sort - function that call partition and use recursivity
 * @array: the array
 * @low: the beginning of the array to start searching
 * @high: the end of the array
 * @size_array: the length of the full array (only for print_array)
 * Return: nothing
 */
void sort(int *array, int low, int high, int size_array)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size_array);
		sort(array, low, p - 1, size_array);
		sort(array, p + 1, high, size_array);
	}

}
/**
 * quick_sort - main function that call only once the sort function to start
 * @array: the array
 * @size: the length of the full array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}
