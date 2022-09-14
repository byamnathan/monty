#include "monty.h"
/**
 * _strcmp - a function that compares two strings
 * @s1: a pointer point to string s1
 * @s2: a pointer point to string s2
 *
 * Return: return 0 if the same, not zero if difference between two strings
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++)
		;
	return (s1[i] - s2[i]);
}

/**
 * get_opcode_fn - a function help to found opcode function
 * @s: a opcode string
 * Return: return a function pointer if found, otherwise NULL
 */
char *(*get_opcode_fn(char *s))(stack_t **, unsigned int, FILE *)
{
	int i;
	instruction_t opcode_fn[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{"pchar", pchar_op},
		{"pstr", pstr_op},
		{"rotl", rotl_op},
		{"rotr", rotr_op},
		{NULL, NULL} };

	if (s == NULL)
		return (NULL);
	for (i = 0; opcode_fn[i].opcode; i++)
	{
		if (_strcmp(s, opcode_fn[i].opcode) == 0)
			return (opcode_fn[i].f);
	}
	return (NULL);
}
