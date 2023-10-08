#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to the head of the list
 * Return: Pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to the head of the list
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head;
	listint_t *fast = *head;
	listint_t *prev_slow = *head;
	listint_t *second_half = NULL;
	int is_palindrome = 1;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	/* Find the middle of the list */
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}

	/* Handle odd length by skipping the middle node */
	if (fast != NULL)
		slow = slow->next;

	/* Reverse the second half of the list */
	second_half = reverse_list(slow);

	/* Compare the first half and reversed second half */
	while (second_half != NULL)
	{
		if (prev_slow->n != second_half->n)
		{
			is_palindrome = 0;
			break;
		}
		prev_slow = prev_slow->next;
		second_half = second_half->next;
	}

	/* Restore the list to its original state */
	reverse_list(slow);
	prev_slow->next = second_half;

	return (is_palindrome);
}
