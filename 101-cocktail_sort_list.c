#include "sort.h"
/**
 * swapnode - swap two node a doubly linked list
 * @list: linked list
 * @nodeP: previous node
 * @nodeS: current node
 * Return: nothing
 */
void swapnode(listint_t **list, listint_t *nodeP, listint_t *nodeS)
{
	if (*list == NULL)
		return;
	if (nodeP == NULL)
		return;
	if (nodeS == NULL)
		return;

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
 * cocktail_sort_list - sort algorithm left to the right
 * and right to the left on a doubly linked list
 * @list: doubly linked list
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int not_sorted = 1, change = 1;
	listint_t *current = *list;

	if (*list == NULL)
		return;
	while (not_sorted)
	{
		not_sorted = 0;
		current = *list;
		while (current && current->next)
		{
			change = 0;
			if (current->n > current->next->n)
			{
				swapnode(list, current, current->next);
				not_sorted = 1;
				change = 1;
				print_list(*list);
			}
			if (change == 0)
				current = current->next;
		}
		if (not_sorted == 0)
			break;
		not_sorted = 0;
		change = 0;
		while (current->prev != NULL)
		{
			change = 0;
			if (current->n < current->prev->n)
			{
				swapnode(list, current->prev, current);
				not_sorted = 1;
				print_list(*list);
				change = 1;
			}
			if (change == 0)
				current = current->prev;
		}
	}
}
