#include "sort.h"

/**
 * hoare_partition - function that check value in array with the pivot value
 * and swap places if needed Hoare style
 * @array: the array
 * @low: the beginning of the array to start searching
 * @high: the end of the array
 * @size_array: the length of the full array (only for print_array)
 * Return: the place of the end or start of the next partition of the array
 */
int hoare_partition(int *array, int low, int high, int size_array)
{
	int pivot = array[high];
	int tmp;
	int i = low - 1;
	int j = high + 1;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size_array);
		}
	}
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
		p = hoare_partition(array, low, high, size_array);
		sort(array, low, p - 1, size_array);
		sort(array, p, high, size_array);
	}

}
/**
 * quick_sort_hoare - main function that call only once the sort function toi
 * start
 * @array: the array
 * @size: the length of the full array
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}
