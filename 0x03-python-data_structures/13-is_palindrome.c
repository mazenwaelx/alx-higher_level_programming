#include "lists.h"

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
    listint_t *mid_node = NULL;
    int is_palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
        return 1;

    /* Find the middle and previous of the last node */
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    /* Handle odd length by skipping the middle node */
    if (fast != NULL)
    {
        mid_node = slow;
        slow = slow->next;
    }

    /* Reverse the second half of the list */
    second_half = slow;
    prev_slow->next = NULL; /* Mark the end of the first half */
    second_half = reverse_list(second_half);

    /* Compare the first half and reversed second half */
    listint_t *ptr1 = *head;
    listint_t *ptr2 = second_half;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->n != ptr2->n)
        {
            is_palindrome = 0;
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    /* Restore the list to its original state */
    second_half = reverse_list(second_half);
    if (mid_node != NULL)
    {
        prev_slow->next = mid_node;
        mid_node->next = second_half;
    }
    else
    {
        prev_slow->next = second_half;
    }

    return is_palindrome;
}
