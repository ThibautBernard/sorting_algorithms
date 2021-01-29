#include "sort.h"


int partition(int *array, int low, int high, int size_array)
{
	int pivot = array[high], tmp = 0;
	int i = low, j;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			i++;
		}
	
	}
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;
	print_array(array, size_array);
	return i;
}

void sort(int *array, int low, int high, int size_array)
{
	int p;
	
	if (low < high)
	{
		p = partition(array, low, high, size_array);
		printf("%d\n", p);
		sort(array, low, p - 1, size_array); /**left**/
		sort(array, p + 1, high, size_array); /** right***/
	}

}

void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}
