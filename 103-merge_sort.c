#include "sort.h"

/**
 * merge - Merges two subarrays of an array of integers
 * @array: The array of integers to be sorted
 * @left: The left subarray
 * @left_size: The size of the left subarray
 * @right: The right subarray
 * @right_size: The size of the right subarray
 */
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *tmp = malloc(sizeof(int) * (left_size + right_size));

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			tmp[k++] = left[i++];
		}
		else
		{
			tmp[k++] = right[j++];
		}
	}

	while (i < left_size)
	{
		tmp[k++] = left[i++];
	}
	while (j < right_size)
	{
		tmp[k++] = right[j++];
	}

	for (i = 0; i < left_size + right_size; i++)
	{
		array[i] = tmp[i];
	}

	printf("[Done]: ");
	print_array(array, left_size + right_size);
	free(tmp);
}

/**
 * merge_sort_recursive - Sorts int array using top-down merge sort algorithm
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */
void merge_sort_recursive(int *array, size_t size)
{
	if (size < 2)
		return;

	size_t middle = size / 2;
	int *left = array;
	int *right = array + middle;
	size_t left_size = middle;
	size_t right_size = size - middle;

	merge_sort_recursive(left, left_size);
	merge_sort_recursive(right, right_size);
	merge(left, left_size, right, right_size, array);
}

/**
 * merge_sort - Sorts int array in ascen order using Merge sort algorithm
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	printf("Array to be sorted:\n");
	print_array(array, size);
	merge_sort_recursive(array, size);
	printf("Sorted array:\n");
	print_array(array, size);
}
