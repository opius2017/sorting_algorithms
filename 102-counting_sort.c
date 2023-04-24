/**
 * counting_sort - Sorts an array of integers using counting sort algorithm
 * @array: Array of integers to be sorted
 * @size: Size of the array to be sorted
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	unsigned int i, k, count;
	int *copy, *count_arr;

	if (array == NULL || size < 2)
		return;
	k = array[0];
	for (i = 0; i < size; i++)
		k = (array[i] > k) ? array[i] : k;
	count_arr = malloc(sizeof(int) * (k + 1));
	if (count_arr == NULL)
		return;
	for (i = 0; i <= k; i++)
		count_arr[i] = 0;
	for (i = 0; i < size; i++)
		count_arr[array[i]] += 1;
	for (i = 1; i <= k; i++)
		count_arr[i] += count_arr[i - 1];
	print_array(count_arr, k + 1);
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
	{
		free(count_arr);
		return;
	}
	for (i = 0; i < size; i++)
	{
		copy[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = copy[i];
	free(copy);
	free(count_arr);
}
