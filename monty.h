#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - dl_list linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: dl_list linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct global_var - global structure to use in the functions
 * @lif: is stack or queue
 * @kont: current line
 * @arg: second parameter inside the current line
 * @head: dl_list linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: dl_list linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_var
{
	int lif;
	unsigned int kont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_struct;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_struct vlg;

/* opcode_instructuions*/
void stack_push(stack_t **stack, unsigned int line_number);
void stack_pall(stack_t **stack, unsigned int line_number);
void stack_pint(stack_t **dl_list, unsigned int tagline);
void stack_pop(stack_t **dl_list, unsigned int tagline);
void stack_swap(stack_t **dl_list, unsigned int tagline);
void stack_queue(stack_t **dl_list, unsigned int tagline);
void stk_stack(stack_t **dl_list, unsigned int tagline);
void stack_add(stack_t **dl_list, unsigned int tagline);
void stack_nop(stack_t **dl_list, unsigned int tagline);
void stack_sub(stack_t **dl_list, unsigned int tagline);
void stack_div(stack_t **dl_list, unsigned int tagline);
void stack_mul(stack_t **dl_list, unsigned int tagline);
void stack_mod(stack_t **dl_list, unsigned int tagline);
void stack_pchar(stack_t **dl_list, unsigned int tagline);
void stack_pstr(stack_t **dl_list, unsigned int tagline);
void stack_rotl(stack_t **dl_list, unsigned int tagline);
void stack_rotr(stack_t **dl_list, unsigned int tagline);

/*get function*/
void (*get_monty_opcode(char *opc))(stack_t **stack, unsigned int line_number);

/*functions imported*/
int stack_sch(char *s, char c);
char *stack_strtokey(char *s, char *d);
void *reallocate(void *ptr, unsigned int old_size, unsigned int new_size);
void *stk_calloc(unsigned int nmemb, unsigned int dimension);
int my_strcmp(char *s1, char *s2);

/* dl_list linked list functions */
stack_t *add_end_node(stack_t **head, const int n);
stack_t *add_int_node(stack_t **head, const int n);
void free_dlistint_struct(stack_t *head);

/* main */
void vlg_free(void);

#endif
