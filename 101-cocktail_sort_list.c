#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the list
 * @a: First node to swap
 * @b: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *prev_a, *next_b;

	prev_a = a->prev;
	next_b = b->next;

	if (prev_a)
		prev_a->next = b;
	else
		*list = b;
	b->prev = prev_a;
	a->prev = b;
	b->next = a;
	a->next = next_b;

	if (next_b)
		next_b->prev = a;
	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Cocktail shaker sort
 *                       algorithm
 * @list: Pointer to pointer to the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left, *right;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		left = *list;
		while (left->next != NULL)
		{
			if (left->n > left->next->n)
			{
				right = left->next;
				swap_nodes(list, left, right);
				swapped = 1;
			}
			else
			{
				left = left->next;
			}
		}

		if (!swapped)
			break;
		swapped = 0;
		right = left;
		while (right->prev != NULL)
		{
			if (right->n < right->prev->n)
			{
				left = right->prev;
				swap_nodes(list, left, right);
				swapped = 1;
			}
			else
			{
				right = right->prev;
			}
		}
	} while (swapped);
}
