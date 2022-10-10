#include<stddef.h>
#include<stdlib.h>
#include "sort.h"

int get_max(int *array, size_t size);
void countSort(int *array, size_t size, int position);

/**
 * radix_sort - sort an array using the radix sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array to be sorted
 */

void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int pos;

	if (array == NULL || size < 2)
		return;

	for (pos = 1; max / pos > 0; pos *= 10)
	{
		countSort(array, size, pos);
	}
}

/**
 * get_max - get the maximum element in an array
 * @array: the array to search for the maximum element
 * @size: the size of the array
 *
 * Return: the maximum value in an array
 */

int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countSort - perform the count sort using position
 * @array: the array to sort
 * @size: the size of the array
 * @position: the radix position to perform the sort on
 */

void countSort(int *array, size_t size, int position)
{
	int count[10] = {0};
	int *copy = malloc(sizeof(int) * size);
	size_t i;

	for (i = 0; i < size; i++)
		count[((array[i] / position) % 10)] += 1;

	for (i = 1; i < 10; i++)
		count[i] = count[i] + count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		copy[--count[(array[i] / position) % 10]] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = copy[i];

	free(copy);

	print_array(array, size);
}
