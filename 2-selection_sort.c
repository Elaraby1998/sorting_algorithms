#include "sort.h"

/**
 * swap_ints - a fun that swap two integers in an array
 * @a: the first integer to swap
 * @b: the second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - a fun that sort an array of integers in ascending order
 * using the selection sort algorithm
 * @array: an array of integers
 * @size: thr size of the array
 * Description: it prints the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t x, j;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min = array + x;
		for (j = x + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + x) != min)
		{
			swap_ints(array + x, min);
			print_array(array, size);
		}
	}
}
