#include "sort.h"


/**
 * shell_sort - Sort array using the Shell Sort Algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 0;
	size_t i, j;
	int tmp;

	while (gap < (size / 3))
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j > 0 && array[j] < array[j - gap]; j -= gap)
			{
				tmp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = tmp;
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
