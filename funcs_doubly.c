#include "monty.h"

/**
 *add_end_node - add a note at the end of the dl_list link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a dl_list linked list
 */
stack_t *add_end_node(stack_t **head, const int n)
{
	stack_t *temporal, *auxiliary;

	if (head == NULL)
		return (NULL);
	temporal = malloc(sizeof(stack_t));
	if (!temporal)
	{
		dprintf(2, "Error: malloc failed\n");
		vlg_free();
		exit(EXIT_FAILURE);
	}
	temporal->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		temporal->next = *head;
		temporal->prev = NULL;
		*head = temporal;
		return (*head);
	}
	auxiliary = *head;
	while (auxiliary->next)
		auxiliary = auxiliary->next;
	temporal->next = auxiliary->next;
	temporal->prev = auxiliary;
	auxiliary->next = temporal;
	return (auxiliary->next);
}

/**
 *add_int_node - add a note at the begining of the dl_list link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a dl_list linked list
 */
stack_t *add_int_node(stack_t **head, const int n)
{
	stack_t *temporal;

	if (head == NULL)
		return (NULL);
	temporal = malloc(sizeof(stack_t));
	if (!temporal)
	{
		dprintf(2, "Error: malloc failed\n");
		vlg_free();
		exit(EXIT_FAILURE);
	}
	temporal->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		temporal->next = *head;
		temporal->prev = NULL;
		*head = temporal;
		return (*head);
	}
	(*head)->prev = temporal;
	temporal->next = (*head);
	temporal->prev = NULL;
	*head = temporal;
	return (*head);
}

/**
 * free_dlistint_struct - frees the dl_list linked list
 *
 * @head: head of the list
 * Return: no return
 */
void free_dlistint_struct(stack_t *head)
{
	stack_t *brief;

	while ((brief = head) != NULL)
	{
		head = head->next;
		free(brief);
	}
}
