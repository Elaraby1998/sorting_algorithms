#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - a fun that sort a subarray of integers
 * @subarr: a subarray of an array of integers to sort
 * @buff: a buffer to store the sorted subarray
 * @front: a front index of the array
 * @mid: a middle index of the array
 * @back: a back index of the array
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t x, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (x = front, j = mid; x < mid && j < back; k++)
		buff[k] = (subarr[x] < subarr[j]) ? subarr[x++] : subarr[j++];
	for (; x < mid; x++)
		buff[k++] = subarr[x];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (x = front, k = 0; x < back; x++)
		subarr[x] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - a fun that implement the merge sort
 * algorithm through recursion
 * @subarr: a subarray of an array of integers to sort
 * @buff: a buffer to store the sorted result
 * @front: the front index of the subarray
 * @back: the back index of the subarray
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - a fun that sort an array of integers in ascending
 * order using the merge sort algorithm
 * @array: an array of integers
 * @size: the size of the array
 * Description: it implements the top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
