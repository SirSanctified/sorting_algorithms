#include<stddef.h>
#include<stdlib.h>
#include "sort.h"

/**
 * selection_sort - sort an array of integers using selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array to sort
 */

void selection_sort(int *array, size_t size)
{
	size_t idx, inner, min, temp;

	for (idx = 0; idx < size - 1; idx++)
	{
		min = idx;

		for (inner = idx + 1; inner < size; inner++)
		{
			if (array[min] > array[inner])
				min = inner;
		}
		if (min != idx)
		{
			temp = array[min];
			array[min] = array[idx];
			array[idx] = temp;
			print_array(array, size);
		}
	}
}
