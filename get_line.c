#include "monty.h"
/**
 * _get_line - gets a line form stdin
 * @lineptr: a pointer to the line
 * @n: the length of the string
 * @stream: the file that is being read from
 * @head: stack
 * Return: *n -1 if lineptr is NULL, or n = i
 */
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream, stack_t *head)
{
	unsigned int maxchar = 1024, i = 0;
	int c;

	(*lineptr) = malloc(maxchar * sizeof(char));
	if ((*lineptr) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(stream);
		if (!head)
			free_dlistint(head);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = fgetc(stream);
		if (c == EOF)
			return (*n = -1);
		if ((i >= maxchar - 2) || c == '\n')
			break;
		(*lineptr)[i++] = c;
	}
	if (i >= maxchar - 2)
	{
		maxchar += maxchar;
		(*lineptr) = _realloc((*lineptr), i, maxchar);
		if ((*lineptr) == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			fclose(stream);
			if (!head)
				free_dlistint(head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		(*lineptr)[i] = '\n';
		(*lineptr)[++i] = '\0';
	}
	return (*n = i);
}

/**
 * _realloc - a function that reallocates block of memory using malloc and free
 * @ptr: a pointer point to old block of memory
 * @old_size: old size of the block of memory
 * @new_size: new size of the block of memory
 *
 * Return: return a pointer point to new block of memory, or NULL if fail
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *block, *ptr1;

	if (new_size <= old_size)
		return (ptr);
	if (ptr == NULL)
	{
		block = malloc(new_size);
		return (block);
	}
	block = malloc(sizeof(*block) * new_size);
	if (block == NULL)
		return (NULL);
	ptr1 = ptr;
	for (i = 0; i < old_size; i++)
		block[i] = ptr1[i];
	free(ptr);
	return (block);
}

/**
 * trun_space - a function that deletes the leading space(se)
 * @str: a string
 * Return: return a string
 */
char *trun_space(char *str)
{
	char *str1;
	static char buffer[5000];
	int len;
	int flag = 0;

	str1 = &buffer[4999];
	*str1 = '\0';
	len = _strlen(str);
	while (len)
	{
		--len;
		if (str[len] != ' ' && str[len] != '\n' && flag == 0)
		{
			*(--str1) = str[len];
			flag = 1;
			continue;
		}
		if (str[len] == ' ' || str[len] == '\n')
			continue;
		if (str[len] != ' ' && str[len + 1] == ' ')
		{
			*(--str1) = ' ';
			*(--str1) = str[len];
		}
		else
		{
			*(--str1) = str[len];
		}
	}
	free(str);
	return ((flag == 0 || str1[0] == '#') ? (NULL) : (str1));
}

/**
 *_strlen - a function that returns the length of a string
 *@s: a pointer point to string
 *
 *Return: return a int number of the length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * read_line - a function gets the opcode from the line
 * @s: line
 * Return: return the opcode string
 */
char *read_line(char *s)
{
	int i;
	static char array[500];

	for (i = 0; s[i] != ' ' && s[i] != '\0' && i != 499; i++)
		array[i] = s[i];
	array[i] = '\0';
	return (array);
}
