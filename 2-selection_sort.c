#include "sort.h"

/**
 * selection_sort - Sort array using the Selection Sort Algorythm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t not_sorted = 1;
	int smallest = array[0];
	int tmp;
	int idx_smallest;

	while (not_sorted)
	{
		not_sorted = 0;

		for (i = 0; i < size; i++)
		{
			smallest = array[i];
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < smallest)
				{
					smallest = array[j];
					idx_smallest = j;
					not_sorted = 1;
				}
			}
			if (not_sorted)
			{
				tmp = array[i];
				array[i] = array[idx_smallest];
				array[idx_smallest] = tmp;
				print_array(array, size);
			}
		}
	}

}
