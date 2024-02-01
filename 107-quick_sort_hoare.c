#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - a fun tha order a subset of an array of integers
 * according to the hoare partition scheme
 * @array: a array of integers
 * @size: a size of the array
 * @left: a starting index of the subset to order
 * @right: a ending index of the subset to order
 * Return: a final partition index
 * Description: it uses the last element of the partition as the pivot
 * Prints array after each swap of two elements
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - a fun tha implement the quicksort algorithm through recursion
 * @array: an array of integers to sort
 * @size: a size of the array
 * @left: a starting index of the array partition to order
 * @right: a ending index of the array partition to order
 * Description: it uses the Hoare partition scheme
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - a fun that sort an array of integers in ascending
 * order using the quicksort algorithm
 * @array: an array of integers
 * @size: a size of the array
 * Description: it uses the Hoare partition scheme
 * Prints the array after each swap of two elements
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
