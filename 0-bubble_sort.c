#include "sort.h"

/**
 * bubble_sort - Sort array using the Bubble Sort Algorythm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	size_t i;
	int tmp;

	if (size > 1 && array != NULL)
	{
		while (swapped)
		{
			swapped = 0;
			for (i = 0; i < size - 1; i++)
			{
				if (array[i] > array[i + 1])
				{
					tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;
					swapped = 1;
					print_array(array, size);
				}
			}
		}
	}
}
