#include "sort.h"
/**
 * swapnode - swap two nodes
 * @list: the doubly linked list
 * @nodeP: the node previous to swap
 * @nodeS: the node next to swap
 * Return: Nothing
 */
void swapnode(listint_t **list, listint_t *nodeP, listint_t *nodeS)
{
	listint_t *t = *list;

	nodeS->prev = nodeP->prev;
	nodeP->next = nodeS->next;
	if (nodeS->next)
		nodeS->next->prev = nodeP;
	nodeS->next = nodeP;
	if (nodeP->prev)
		nodeP->prev->next = nodeS;
	if (nodeP->prev == NULL)
		*list = nodeS;
	nodeP->prev = nodeS;
}
/**
 * insertion_sort_list -  sorts a doubly linked list
 * of integers in ascending order
 * @list: doubly linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current = (*list)->next, *previous, *swap;

	while (swapped)
	{
		swapped = 0;
		while (current)
		{
			swap = current;
			previous = swap->prev;
			if (swap->n < previous->n)
			{
				while (previous)
				{
					if (swap->n < previous->n)
					{
						swapnode(list, previous, swap);
						print_list(*list);
						previous = swap;
						swapped = 1;
					}
					previous = previous->prev;
				}
			}
			current = current->next;
		}
	}
}
