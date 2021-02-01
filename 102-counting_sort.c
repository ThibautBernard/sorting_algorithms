#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * find_max - find the max integer in an array
 * @array: array to loop on
 * @size: length of the array
 * Return: the max value
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
 * counting_sort - sort algorithm
 * create two temporary array
 * @array: the array to sort
 * @size: size of the array
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int  y = 0, tmp = 0, idx = 0, max = 0, *arr_idx;
	int *output;
	size_t i;

	if (array == NULL || size < 2)
		return;
	max = find_max(array, size);
	arr_idx = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * (size + 1));
	if (arr_idx == NULL)
		return;
	if (output == NULL)
		return;
	fill_array(arr_idx, max, NULL, 0);
	for (i = 0; i < size; i++)
		arr_idx[array[i]] += 1;
	for (y = 1; y <= max; y++)
		arr_idx[y] = arr_idx[y - 1] + arr_idx[y];
	print_array(arr_idx, max + 1);
	for (i = 0; i < size; i++)
	{
		tmp = array[i];
		idx = arr_idx[tmp] - 1;
		arr_idx[tmp] -= 1;
		output[idx] = array[i];
	}
	fill_array(array, size, output, 0);
	free(arr_idx);
	free(output);
}
