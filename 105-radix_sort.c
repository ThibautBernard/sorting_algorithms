#include "sort.h"

/**
 * find_max - find the max integer
 * @array: The array
 * @size: The size of the array
 * Return: The max integer of the arrat
 */
int find_max(int *array, size_t size)
{
	size_t i = 0;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * fill_array - fill an array
 * @array: array to fill
 * @size: size of the array
 * @something: NULL or array of int to loop on
 * @something_const: integer to fill in the array
 * Return: nothing
 */
void fill_array(int *array, size_t size, int *something, int something_const)
{
	size_t i;

	if (something)
	{
		for (i = 0; i < size; i++)
			array[i] = something[i];
	}
	else
	{
		for (i = 0; i <= size; i++)
			array[i] = something_const;
	}
}
/**
 * counting_srt - sort algorithm
 * create two temporary array
 * @array: the array to sort
 * @size: size of the array
 * @place: place
 * Return: nothing
 */
void counting_srt(int *array, size_t size, size_t place)
{
	int i, y, *arr_idx;
	int *output;
	size_t max;

	max = (array[0] / place) % 10;
	for (i = 1; i < (int)size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}
	arr_idx = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * (size + 1));
	if (arr_idx == NULL)
		return;
	if (output == NULL)
		return;
	fill_array(arr_idx, max, NULL, 0);

	for (i = 0; i < (int)size; i++)
		arr_idx[(array[i] / place) % 10] += 1;
	for (y = 1; y <= (int)max; y++)
		arr_idx[y] = arr_idx[y - 1] + arr_idx[y];
	for (i = size - 1; i >= 0; i--)
	{
		output[arr_idx[(array[i] / place) % 10] - 1] = array[i];
		arr_idx[(array[i] / place) % 10]--;
	}
	fill_array(array, size, output, 0);
	free(arr_idx);
	free(output);
}
/**
 * radix_sort - main function that does the algorithm
 * radix sort
 * @array: The array
 * @size: The size of the array
 * Return: The max integer of the arrat
 */
void radix_sort(int *array, size_t size)
{
	size_t max;
	size_t place;

	if (array == NULL || size < 2)
		return;
	max = find_max(array, size);
	for (place = 1; max / place > 0; place *= 10)
	{
		counting_srt(array, size, place);
		print_array(array, size);
	}
}

