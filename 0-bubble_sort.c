#include "sort.h"

/**
 * swap_ints - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *        using the Bubble sort algorithm
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int bubbly = 0;

	if (array == NULL || size < 2)
		return;

	while (bubbly == 0)
	{
		bubbly = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = 0;
			}
		}
		len--;
	}
}
