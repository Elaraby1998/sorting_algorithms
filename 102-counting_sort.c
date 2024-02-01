#include "sort.h"

/**
 * get_max - a fun that get the maximum value in an array of integers
 * @array: an array of integers
 * @size: the size of the array
 * Return: a maximum integer in the array
 */
int get_max(int *array, int size)
{
	int max, x;

	for (max = array[0], x = 1; x < size; x++)
	{
		if (array[x] > max)
			max = array[x];
	}

	return (max);
}

/**
 * counting_sort - a fun that sort an array of integers in ascending order
 * using the counting sort algorithm
 * @array: an array of integers
 * @size: the size of the array
 * Description: itrints the counting array after setting it up
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, x;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (x = 0; x < (max + 1); x++)
		count[x] = 0;
	for (x = 0; x < (int)size; x++)
		count[array[x]] += 1;
	for (x = 0; x < (max + 1); x++)
		count[x] += count[x - 1];
	print_array(count, max + 1);

	for (x = 0; x < (int)size; x++)
	{
		sorted[count[array[x]] - 1] = array[x];
		count[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[x] = sorted[x];

	free(sorted);
	free(count);
}
