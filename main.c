#include "monty.h"

global_struct vlg;

/**
 * vlg_free - frees the global variables
 *
 * Return: no return
 */
void vlg_free(void)
{
	free_dlistint_struct(vlg.head);
	free(vlg.buffer);
	fclose(vlg.fd);
}

/**
 * start_vglo - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_vglo(FILE *fd)
{
	vlg.lif = 1;
	vlg.kont = 1;
	vlg.arg = NULL;
	vlg.head = NULL;
	vlg.fd = fd;
	vlg.buffer = NULL;
}

/**
 * check_entry - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_entry(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t dimension = 256;
	ssize_t num_lines = 0;
	char *delineations[2] = {NULL, NULL};

	fd = check_entry(argc, argv);
	start_vglo(fd);
	num_lines = getline(&vlg.buffer, &dimension, fd);
	while (num_lines != -1)
	{
		delineations[0] = stack_strtokey(vlg.buffer, " \t\n");
		if (delineations[0] && delineations[0][0] != '#')
		{
			f = get_monty_opcode(delineations[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vlg.kont);
				dprintf(2, "unknown instruction %s\n", delineations[0]);
				vlg_free();
				exit(EXIT_FAILURE);
			}
			vlg.arg = stack_strtokey(NULL, " \t\n");
			f(&vlg.head, vlg.kont);
		}
		num_lines = getline(&vlg.buffer, &dimension, fd);
		vlg.kont++;
	}

	vlg_free();

	return (0);
}
