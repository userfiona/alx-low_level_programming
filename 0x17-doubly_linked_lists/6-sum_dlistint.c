#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data (n) of a,
 * dlistint_t linked list.
 * @head: Double pointer to the head of the list.
 *
 * Return: The sum of all the data values in the list,
 * If the list is empty, returns 0.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
