#include "monty.h"

/**
 * stack_queue - sets the format of the data to a queue (FIFO)
 *
 * @dl_list: head of the linked list
 * @tagline: line number;
 * Return: no return
 */
void stack_queue(stack_t **dl_list, unsigned int tagline)
{
	(void)dl_list;
	(void)tagline;

	vlg.lif = 0;
}

/**
 * stk_stack - sets the format fo the data to a stack (LIFO)
 *
 * @dl_list: head of the linked list
 * @tagline: line number;
 * Return: no return
 */
void stk_stack(stack_t **dl_list, unsigned int tagline)
{
	(void)dl_list;
	(void)tagline;

	vlg.lif = 1;
}

/**
 * stack_add - adds the top two elements of the stack
 *
 * @dl_list: head of the linked list
 * @tagline: line number;
 * Return: no return
 */
void stack_add(stack_t **dl_list, unsigned int tagline)
{
	int m = 0;
	stack_t *auxiliary = NULL;

	auxiliary = *dl_list;

	for (; auxiliary != NULL; auxiliary = auxiliary->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", tagline);
		vlg_free();
		exit(EXIT_FAILURE);
	}

	auxiliary = (*dl_list)->next;
	auxiliary->n += (*dl_list)->n;
	stack_pop(dl_list, tagline);
}

/**
 * stack_nop - doesn't do anythinhg
 *
 * @dl_list: head of the linked list
 * @tagline: line number;
 * Return: no return
 */
void stack_nop(stack_t **dl_list, unsigned int tagline)
{
	(void)dl_list;
	(void)tagline;
}

/**
 * stack_sub - subtracts the top element to the second top element of the stack
 *
 * @dl_list: head of the linked list
 * @tagline: line number;
 * Return: no return
 */
void stack_sub(stack_t **dl_list, unsigned int tagline)
{
	int m = 0;
	stack_t *auxiliary = NULL;

	auxiliary = *dl_list;

	for (; auxiliary != NULL; auxiliary = auxiliary->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", tagline);
		vlg_free();
		exit(EXIT_FAILURE);
	}

	auxiliary = (*dl_list)->next;
	auxiliary->n -= (*dl_list)->n;
	stack_pop(dl_list, tagline);
}
