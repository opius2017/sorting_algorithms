#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list in ascending order
 *                      using the Cocktail shaker sort algorithm
 *
 * @list: double pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = *list, *end = NULL, *curr = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped == 1)
	{
		swapped = 0;
		curr = start;
		while (curr->next != end)
		{
			if (curr->n > curr->next->n)
			{
				tmp = curr->next;
				if (curr->prev)
					curr->prev->next = tmp;
				else
					start = tmp;
				tmp->prev = curr->prev;
				curr->next = tmp->next;
				if (tmp->next)
					tmp->next->prev = curr;
				tmp->next = curr;
				curr->prev = tmp;
				swapped = 1;
				print_list(*list);
			}
			else
				curr = curr->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		end = curr;
		while (curr->prev != start)
		{
			if (curr->n < curr->prev->n)
			{
				tmp = curr->prev;
				if (tmp->prev)
					tmp->prev->next = curr;
				else
					start = curr;
				curr->prev = tmp->prev;
				tmp->next = curr->next;
				if (curr->next)
					curr->next->prev = tmp;
				curr->next = tmp;
				tmp->prev = curr;
				swapped = 1;
				print_list(*list);
			}
			else
				curr = curr->prev;
		}
		start = curr;
	}
}
