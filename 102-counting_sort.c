#include "sort.h"
/**
 * counting_sort - sorts int array in asce order with Counting sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	int *count_array, *new_array;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
		return;
	for (i = 0; i <= max; i++)
		count_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;
	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];
	new_array = malloc(sizeof(int) * size);
	if (new_array == NULL)
	{
		free(count_array);
		return;
		}
	for (i = (int)size - 1; i >= 0; i--)
	{
		new_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
		}
	for (i = 0; i < (int)size; i++)
		array[i] = new_array[i];
	free(count_array);
	free(new_array);
}
