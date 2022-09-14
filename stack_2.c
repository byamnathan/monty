#include "monty.h"

/**
 * dlistint_len - a function returns number of nodes
 * @h: points to head
 *
 * Return: return number of nodes
 */

size_t dlistint_len(stack_t **h)
{
	stack_t *current;
	size_t i = 0;

	current = *h;
	if (!current)
		return (i);
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

/**
 * swap_op - a function swaps the top two Node value in the stack
 * @h: points to head
 * @l: line
 * @fd: file stream
 * Return: return NULL on success, EXIT_FAILURE on fail
 */
char *swap_op(stack_t **h, unsigned int l, FILE *fd)
{
	size_t i;
	int temp;
	stack_t *current;

	current = *h;
	i = dlistint_len(h);
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l);
		if (*h)
			free_dlistint(*h);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
	return (NULL);
}

/**
 * add_op - a function adds the top two Node value in the stack
 * @h: points to head
 * @l: line
 * @fd: file stream
 * Return: return NULL on success, EXIT_FAILURE on fail
 */
char *add_op(stack_t **h, unsigned int l, FILE *fd)
{
	size_t i;
	stack_t *current;

	current = *h;
	i = dlistint_len(h);
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l);
		if (*h)
			free_dlistint(*h);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	current->next->n += current->n;
	(*h) = current->next;
	(*h)->prev = NULL;
	free(current);
	return (NULL);
}

/**
 * free_dlistint - a function frees the double linked list
 * @head: points to head
 * Return: void
 */

void free_dlistint(stack_t *head)
{
	stack_t *current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * nop_op - a function does nothing
 * @h: points to head
 * @l: line
 * @fd: file stream
 * Return: always return NULL
 */
char *nop_op(stack_t **h, unsigned int l, FILE *fd)
{
	(void)l;
	(void)fd;
	(void)h;
	return (NULL);
}
