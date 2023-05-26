#include "monty.h"

/**
 * get_monty_opcode - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_monty_opcode(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t direct[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_pop},
		{"swap", stack_swap},
		{"queue", stack_queue},
		{"stack", stk_stack},
		{"add", stack_add},
		{"nop", stack_nop},
		{"sub", stack_sub},
		{"mul", stack_mul},
		{"div", stack_div},
		{"mod", stack_mod},
		{"pchar", stack_pchar},
		{"pstr", stack_pstr},
		{"rotl", stack_rotl},
		{"rotr", stack_rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; direct[i].opcode; i++)
	{
		if (my_strcmp(direct[i].opcode, opc) == 0)
			break;
	}

	return (direct[i].f);
}
