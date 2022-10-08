#include<stddef.h>
#include<stdlib.h>
#include "sort.h"

int partition(int *array, int lower_bound, int upper_bound, size_t size);
void q_sort(int *array, int lb, int ub, size_t size);
void swap(int *array, int a, int b);

/**
 * quick_sort - sort an array of integers using quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	q_sort(array, 0, size - 1, size);
	
}

int partition(int *array, int lower_bound, int upper_bound, size_t size)
{
	int pivot = array[upper_bound];
	int start = lower_bound;
	int end = upper_bound;

	while(start < end)
	{
		while (array[start] <= pivot)
		{
			start++;
		}
		while (array[end] > pivot)
		{
			end--;
		}
		if (start < end)
		{
			swap(array, start, end);
			print_array(array, size);
		}
	}
	swap(array, lower_bound, end);
	return end;
}

void q_sort(int *array, int lb, int ub, size_t size)
{
	int loc;

	if (lb < ub)
	{
		loc = partition(array, lb, ub, size);
		q_sort(array, lb, loc - 1, size);
		q_sort(array, loc + 1, ub, size);
	}
}

void swap(int *array, int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
