#include<stdlib.h>
#include<stddef.h>
#include<stdio.h>
#include "sort.h"

void swap(int *a, int *b);
void merge(int *array, size_t size, size_t start, size_t seq, char flow);
void b_seq(int *array, size_t size, size_t start, size_t seq, char flow);

/**
 * merge - sort a bitonic seqeunce inside an array of integers
 * @array: an array of integers
 * @size: size of the array
 * @start: start index of the sequence in the array to sort
 * @seq: the size of the sequence to sort
 * @flow: the direction ti sort in
 */

void merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
				(flow == DOWN && array[i] < array[i + jump]))
				swap(array + i, array + i + jump);
		}
		merge(array, size, start, jump, flow);
		merge(array, size, start + jump, jump, flow);
	}
}

/**
 * b_seq - convert an array of integers into a bitonic sequence
 * @array: an array of integers
 * @size: the size of the array
 * @start: the starting index of a block of the bitonic sequence
 * @seq: the size of a block of the bitonic sequence
 * @flow: the direction to sort the bitonic sequence in
 */

void b_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		b_seq(array, size, start, cut, UP);
		b_seq(array, size, start + cut, cut, DOWN);
		merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * swap - swap two integers in an array
 * @a: the first integer
 * @b: the second integer
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_sort - sort an array of integers using bitonic sort algorithm
 * @array: the array to sort
 * @size: the array size
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	b_seq(array, size, 0, size, UP);
}
