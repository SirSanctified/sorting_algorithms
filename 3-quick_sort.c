#include<stddef.h>
#include<stdlib.h>
#include "sort.h"

void swap(int *array, int a, int b);
int partition(int *array, int lb, int ub, size_t size);
void q_sort(int *array, int lb, int ub, size_t size);

/**
 * quick_sort - sort an array of integers using quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{

	q_sort(array, 0, size - 1, size);
}

/**
 * swap - swap array elements
 * @array: the array whose elements are to be swapped
 * @a: the first element
 * @b: the second element
 */

void swap(int *array, int a, int b)
{
	if (array[a] != array[b])
	{
		int temp = array[a];

		array[a] = array[b];
		array[b] = temp;
	}
}

/**
 * partition - perform the lumuto partitioning
 * @array: the array to partition
 * @lb: the lower bound
 * @ub: the upper bound
 * @size: the size of the array
 *
 * Return: the position between two partitions
 */

int partition(int *array, int lb, int ub, size_t size)
{
	int pivot = array[ub];
	int j = lb - 1;
	int i;

	for (i = lb; i < ub; i++)
	{
		if (array[i] <= pivot)
		{
			j += 1;
			swap(array, i, j);
		}
	}
	swap(array, ub, j + 1);
	print_array(array, size);
	return (j + 1);
}

/**
 * q_sort - perform the sorting
 * @array: the array to sort
 * @lb: the lower bound
 * @ub: the upper bound
 * @size:; the size of the array
 */

void q_sort(int *array, int lb, int ub, size_t size)
{
	int part;

	if (lb < ub)
	{
		part = partition(array, lb, ub, size);
		q_sort(array, lb, part - 1, size);
		q_sort(array, part + 1, ub, size);
	}
}
