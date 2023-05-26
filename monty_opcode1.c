#include "monty.h"

/**
 * stack_push - pushes an element to the stack
 *
 * @dl_list: head of the linked list
 * @tagline: line number
 * Return: no return
 */
void stack_push(stack_t **dl_list, unsigned int tagline)
{
	int n, j;

	if (!vlg.arg)
	{
		dprintf(2, "L%u: ", tagline);
		dprintf(2, "usage: push integer\n");
		vlg_free();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vlg.arg[j] != '\0'; j++)
	{
		if (!isdigit(vlg.arg[j]) && vlg.arg[j] != '-')
		{
			dprintf(2, "L%u: ", tagline);
			dprintf(2, "usage: push integer\n");
			vlg_free();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vlg.arg);

	if (vlg.lif == 1)
		add_int_node(dl_list, n);
	else
		add_end_node(dl_list, n);
}

/**
 * stack_pall - prints all values on the stack
 *
 * @dl_list: head of the linked list
 * @tagline: line numbers
 * Return: no return
 */
void stack_pall(stack_t **dl_list, unsigned int tagline)
{
	stack_t *auxiliary;
	(void)tagline;

	auxiliary = *dl_list;

	while (auxiliary)
	{
		printf("%d\n", auxiliary->n);
		auxiliary = auxiliary->next;
	}
}

/**
 * stack_pint - prints the value at the top of the stack
 *
 * @dl_list: head of the linked list
 * @tagline: line number
 * Return: no return
 */
void stack_pint(stack_t **dl_list, unsigned int tagline)
{
	(void)tagline;

	if (*dl_list == NULL)
	{
		dprintf(2, "L%u: ", tagline);
		dprintf(2, "can't pint, stack empty\n");
		vlg_free();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*dl_list)->n);
}

/**
 * stack_pop - removes the top element of the stack
 *
 * @dl_list: head of the linked list
 * @tagline: line number
 * Return: no return
 */
void stack_pop(stack_t **dl_list, unsigned int tagline)
{
	stack_t *auxiliary;

	if (dl_list == NULL || *dl_list == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", tagline);
		vlg_free();
		exit(EXIT_FAILURE);
	}
	auxiliary = *dl_list;
	*dl_list = (*dl_list)->next;
	free(auxiliary);
}

/**
 * stack_swap - swaps the top two elements of the stack
 *
 * @dl_list: head of the linked list
 * @tagline: line number
 * Return: no return
 */
void stack_swap(stack_t **dl_list, unsigned int tagline)
{
	int m = 0;
	stack_t *auxiliary = NULL;

	auxiliary = *dl_list;

	for (; auxiliary != NULL; auxiliary = auxiliary->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", tagline);
		vlg_free();
		exit(EXIT_FAILURE);
	}

	auxiliary = *dl_list;
	*dl_list = (*dl_list)->next;
	auxiliary->next = (*dl_list)->next;
	auxiliary->prev = *dl_list;
	(*dl_list)->next = auxiliary;
	(*dl_list)->prev = NULL;
}
