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
	int smallest;
	int tmp;

	if (array != NULL)
	{
		smallest = array[0];
		while (not_sorted)
		{
			not_sorted = 0;

			for (i = 0; i < size; i++)
			{
				smallest = i;
				for (j = i + 1; j < size; j++)
				{
					if (array[j] < array[smallest])
					{
						smallest = j;
						not_sorted = 1;
					}
				}
				if (not_sorted)
				{
					tmp = array[i];
					array[i] = array[smallest];
					array[smallest] = tmp;
					print_array(array, size);
					not_sorted = 0;
				}
			}
		}
	}

}
