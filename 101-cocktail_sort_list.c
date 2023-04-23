#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
        if (node1->prev)
                node1->prev->next = node2;
        if (node2->next)
                node2->next->prev = node1;
        node1->next = node2->next;
        node2->prev = node1->prev;
        node1->prev = node2;
        node2->next = node1;
}
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: Pointer to a pointer to the head of the list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *left = *list, *right = NULL, *curr = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		while (left->next != right)
		{
			if (left->n > left->next->n)
			{
				if (left == *list)
					*list = left->next;
				swap_nodes(left, left->next);
				print_list(*list);
				swapped = 1;
			} else
			{
				left = left->next;
			}
		} right = left;
		if (swapped == 0)
			break;
		swapped = 0;
		while (right->prev != curr)
		{
			if (right->n < right->prev->n)
			{
				if (right->prev == *list)
					*list = right;
				swap_nodes(right->prev, right);
				print_list(*list);
				swapped = 1;
			} else
			{
				right = right->prev;
			}
		} curr = right;
	} while (swapped);
}
