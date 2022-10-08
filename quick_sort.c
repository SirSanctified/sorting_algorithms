#include<stddef.h>
#include<stdlib.h>
#include "sort.h"

void swap(int *array, int a, int b);
void partition(int *array, int lb, int ub, size_t size);

/**
 * quick_sort - sort an array of integers using quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	partition(array, 0, size - 1, size);
}

void swap(int *array, int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void partition(int *array, int lb, int ub, size_t size)
{
	int pivot = array[ub];
	int j = lb;
	int i;

	if (lb >= ub)
		return;

	for (i = lb; i < ub; i++)
	{
		if (array[i] <= pivot)
		{
			swap(array, i, j);
			print_array(array, size);
			j += 1;
		}
	}
	swap(array, ub, j);

	partition(array, lb, j - 1, size);
	partition(array, j + 1, ub, size);
}
