#include "monty.h"
/**
 * pstr_op - a function prints the string at the the stack
 * @h: points to head
 * @l: line
 * @fd: file stream
 * Return: return NULL on success, EXIT_FAILURE on fail
 */
char *pstr_op(stack_t **h, unsigned int l, FILE *fd)
{
	int c;
	stack_t *current;
	(void)l;
	(void)fd;

	current = *h;
	if (!(*h))
	{
		fprintf(stdout, "\n");
		return (NULL);
	}
	while (current)
	{
		c = current->n;
		if (c <= 0 || c > 127)
			break;
		fprintf(stdout, "%c", c);
		current = current->next;
	}
	fprintf(stdout, "\n");
	return (NULL);
}

/**
 * rotl_op - a function rotates the stack
 * @h: points to head
 * @l: line
 * @fd: file stream
 * Return: return NULL on success
 */
char *rotl_op(stack_t **h, unsigned int l, FILE *fd)
{
	stack_t *current, *tail;
	(void)l;
	(void)fd;

	tail = current = *h;
	if (current == NULL || current->next == NULL)
		return (NULL);
	while (tail->next)
		tail = tail->next;
	(*h) = current->next;
	(*h)->prev = NULL;
	tail->next = current;
	current->prev = tail;
	current->next = NULL;
	return (NULL);
}

/**
 * rotr_op - a function rotates the stack upside down
 * @h: points to head
 * @l: line
 * @fd: file stream
 * Return: return NULL on success
 */
char *rotr_op(stack_t **h, unsigned int l, FILE *fd)
{
	stack_t *current, *next, *prev, *result = NULL;
	(void)l;
	(void)fd;

	current = *h;
	if (!(*h) || (*h)->next == NULL)
		return (NULL);
	while (current)
	{
		next = current->next;
		current->next = result;
		result = current;
		current = next;
	}
	(*h) = result;
	current = result;
	result = NULL;
	while (current)
	{
		prev = current->prev;
		current->prev = result;
		result = current;
		current = prev;
	}
	return (NULL);
}
