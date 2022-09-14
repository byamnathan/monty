#ifndef _MONTY_H
#define _MONTY_H
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
extern char *global_line;   /* Declaration the global variable */
char *global_line;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	char *(*f)(stack_t **stack, unsigned int line_number, FILE *fd);
} instruction_t;

/* The following are prototypes */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream, stack_t *head);
char *trun_space(char *str);
char *(*get_opcode_fn(char *s))(stack_t **, unsigned int, FILE *);
int _atoi(char *s);
int _strlen(char *s);
char *read_line(char *s);
int _strcmp(char *s1, char *s2);
char *push_op(stack_t **h, unsigned int l, FILE *fd);
char *pall_op(stack_t **h, unsigned int l, FILE *fd);
stack_t *add_dnodeint(stack_t **head, int n, FILE *fd);
char *pint_op(stack_t **h, unsigned int l, FILE *fd);
char *pop_op(stack_t **h, unsigned int l, FILE *fd);
char *swap_op(stack_t **h, unsigned int l, FILE *fd);
size_t dlistint_len(stack_t **h);
void free_dlistint(stack_t *head);
char *add_op(stack_t **h, unsigned int l, FILE *fd);
char *nop_op(stack_t **h, unsigned int l, FILE *fd);
FILE *open_file(char *file_name);
char *sub_op(stack_t **h, unsigned int l, FILE *fd);
void unknown_op(unsigned int line_n, char *cmd, stack_t *head, FILE *fd);
char *div_op(stack_t **h, unsigned int l, FILE *fd);
char *mul_op(stack_t **h, unsigned int l, FILE *fd);
char *mod_op(stack_t **h, unsigned int l, FILE *fd);
char *pchar_op(stack_t **h, unsigned int l, FILE *fd);
char *pstr_op(stack_t **h, unsigned int l, FILE *fd);
char *rotl_op(stack_t **h, unsigned int l, FILE *fd);
char *rotr_op(stack_t **h, unsigned int l, FILE *fd);

#endif /* _MONTY_H */
