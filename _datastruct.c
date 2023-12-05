#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * __printlist - a function to print all the elements of a
 * list_t list
 * @h: pointer to the head of the list.
 *
 * Return: returns number of elements
 */

size_t __printlist(_path *h)
{
	unsigned int i;

	for (i = 0; h != NULL; i++)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
	}

	return (i);
}

/**
 * __freelist - frees a linked list
 * @head: list_t list to be freed
 */
<<<<<<< HEAD
void __freelist(_path *head)
=======

void __freelist(list_t *head)
>>>>>>> f300c33aba2b689390e1715e6ceaf729dea5499f
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
