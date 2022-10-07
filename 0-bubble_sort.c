#include<stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 **/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size > 2)
	{
		for (i = 0; i < size - 1; i++)
		{
			int hasSwapped = 0;

			for (j = 0; j < size - 1 - i; j++)
			{
				if (array[j] > array[j + 1])
				{
					int temp = array[j];

					array[j] = array[j + 1];
					array[j + 1] = temp;
					print_array(array, size);
					hasSwapped = 1;
				}
			}

			if (hasSwapped == 0)
				break;

		}
	}
}
