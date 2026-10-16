#include "lists.h"
#include <stddef.h>

/**
 *  * reverse_listint - reverses a singly linked list
 *   * @head: pointer to pointer of head node
 *    *
 *     * Return: pointer to the first node of the reversed list
 *      */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;
	listint_t *next = NULL;


	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
	return (*head);
}

/**
 *  * is_palindrome - checks if a singly linked list is a palindrome
 *   * @head: double pointer to head of listint_t list
 *    *
 *     * Return: 1 if it is a palindrome, 0 if it is not
 *      */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *first_half, *second_half;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (1);

	slow = *head;
	fast = *head;

	/* Find middle using fast and slow pointers */
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	/* Reverse the second half of the list */
	second_half = reverse_listint(&(slow->next));
	first_half = *head;

	/* Compare values of first half and reversed second half */
	while (second_half != NULL)
	{
		if (first_half->n != second_half->n)
			return (0);
		first_half = first_half->next;
		second_half = second_half->next;
	}

	return (1);
}
