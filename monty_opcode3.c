#include "monty.h"

/**
 * stack_div - divides the second element by the top element of the stack
 *
 * @dl_list: head of the linked list
 * @tagline: line number;
 * Return: no return
 */
void stack_div(stack_t **dl_list, unsigned int tagline)
{
	int m = 0;
	stack_t *auxiliary = NULL;

	auxiliary = *dl_list;

	for (; auxiliary != NULL; auxiliary = auxiliary->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", tagline);
		vlg_free();
		exit(EXIT_FAILURE);
	}

	if ((*dl_list)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", tagline);
		vlg_free();
		exit(EXIT_FAILURE);
	}

	auxiliary = (*dl_list)->next;
	auxiliary->n /= (*dl_list)->n;
	stack_pop(dl_list, tagline);
}

/**
 * stack_mul - multiplies the top element to the second top element of the stack
 *
 * @dl_list: head of the linked list
 * @tagline: line number;
 * Return: no return
 */
void stack_mul(stack_t **dl_list, unsigned int tagline)
{
	int m = 0;
	stack_t *auxiliary = NULL;

	auxiliary = *dl_list;

	for (; auxiliary != NULL; auxiliary = auxiliary->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", tagline);
		vlg_free();
		exit(EXIT_FAILURE);
	}

	auxiliary = (*dl_list)->next;
	auxiliary->n *= (*dl_list)->n;
	stack_pop(dl_list, tagline);
}

/**
 * stack_mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @dl_list: head of the linked list
 * @tagline: line number;
 * Return: no return
 */
void stack_mod(stack_t **dl_list, unsigned int tagline)
{
	int m = 0;
	stack_t *auxiliary = NULL;

	auxiliary = *dl_list;

	for (; auxiliary != NULL; auxiliary = auxiliary->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", tagline);
		vlg_free();
		exit(EXIT_FAILURE);
	}

	if ((*dl_list)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", tagline);
		vlg_free();
		exit(EXIT_FAILURE);
	}

	auxiliary = (*dl_list)->next;
	auxiliary->n %= (*dl_list)->n;
	stack_pop(dl_list, tagline);
}
/**
 * stack_pchar - print the char value of the first element
 *
 * @dl_list: head of the linked list
 * @tagline: line number;
 * Return: no return
 */
void stack_pchar(stack_t **dl_list, unsigned int tagline)
{
	if (dl_list == NULL || *dl_list == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", tagline);
		vlg_free();
		exit(EXIT_FAILURE);
	}
	if ((*dl_list)->n < 0 || (*dl_list)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", tagline);
		vlg_free();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*dl_list)->n);
}

/**
 * stack_pstr - prints the string of the stack
 *
 * @dl_list: head of the linked list
 * @tagline: line number;
 * Return: no return
 */
void stack_pstr(stack_t **dl_list, unsigned int tagline)
{
	stack_t *auxiliary;
	(void)tagline;

	auxiliary = *dl_list;

	while (auxiliary && auxiliary->n > 0 && auxiliary->n < 128)
	{
		printf("%c", auxiliary->n);
		auxiliary = auxiliary->next;
	}

	printf("\n");
}
