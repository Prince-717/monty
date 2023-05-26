#include "monty.h"

/**
 * stack_rotl - rotates the first element to the bottom and  the second to the top
 *
 * @dl_list: head of the linked list
 * @tagline: line number;
 * Return: no return
 */



void stack_rotl(stack_t **dl_list, unsigned int tagline)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)tagline;

	if (*dl_list == NULL)
		return;

	if ((*dl_list)->next == NULL)
		return;

	aux1 = (*dl_list)->next;
	aux2 = *dl_list;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *dl_list;
	(*dl_list)->next = NULL;
	(*dl_list)->prev = aux2;
	*dl_list = aux1;
}

/**
 * stack_rotr - reverse the stack
 *
 * @dl_list: head of the linked list
 * @tagline: line number
 * Return: no return
 */
void stack_rotr(stack_t **dl_list, unsigned int tagline)
{
	stack_t *auxiliary = NULL;
	(void)tagline;

	if (*dl_list == NULL)
		return;

	if ((*dl_list)->next == NULL)
		return;

	auxiliary = *dl_list;

	for (; auxiliary->next != NULL; auxiliary = auxiliary->next)
		;

	auxiliary->prev->next = NULL;
	auxiliary->next = *dl_list;
	auxiliary->prev = NULL;
	(*dl_list)->prev = auxiliary;
	*dl_list = auxiliary;
}
