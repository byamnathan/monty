#include "monty.h"
/**
 * main - a function interpretes the Monty opcode
 * @argc: number of arguments
 * @argv: content of arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE if fail
 */
int main(int argc, char **argv)
{
	char *cmd, *line = NULL;
	FILE *fd;
	stack_t *head = NULL;
	size_t len;
	unsigned int line_n = 0;
	char *(*found_opcode)(stack_t **, unsigned int, FILE *);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open_file(argv[1]);
	while (1)
	{
		if ((_get_line(&line, &len, fd, head)) == -1)
		{
			if (line)
				free(line);
			break;
		}
		global_line = trun_space(line);
		++line_n;
		if (global_line == NULL)
			continue;
		cmd = read_line(global_line);
		found_opcode = get_opcode_fn(cmd);
		if (found_opcode != NULL)
			found_opcode(&head, line_n, fd);
		else
			unknown_op(line_n, cmd, head, fd);
	}
	if (head)
		free_dlistint(head);
	fclose(fd);
	return (EXIT_SUCCESS);
}
