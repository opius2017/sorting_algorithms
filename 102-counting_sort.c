#include "sort.h"
/**
 * counting_sort - Sorts array of integers with counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max_num = 0;
	size_t i, j;

	int *count_array = NULL, *sorted_array = NULL;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
		}
	count_array = malloc(sizeof(int) * (max_num + 1));
	if (!count_array)
		return;
	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
	{
		free(count_array);
		return;
		}
	for (i = 0; i <= max_num; i++)
		count_array[i] = 0;
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	printf("Count array:\n");
	for (i = 0; i <= max_num; i++)
		printf("%d: %d\n", (int)i, count_array[i]);
	printf("\n");
	for (i = 1; i <= max_num; i++)
		count_array[i] += count_array[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
	{
		j = count_array[array[i]] - 1;
		sorted_array[j] = array[i];
		count_array[array[i]]--;
		}
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	free(count_array);
	free(sorted_array);
}
