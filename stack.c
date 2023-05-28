/*
 * File: stack.c
 * Auth: Maxwell Mwirigi
 */

#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/*Frees a stack_t stack.*/
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/*Initializes a stack_t stack with beginning stack and ending queue nodes.*/
int init_stack(stack_t **stack)
{
	stack_t *stk;

	stk = malloc(sizeof(stack_t));
	if (stk == NULL)
		return (malloc_error());

	stk->n = STACK;
	stk->prev = NULL;
	stk->next = NULL;

	*stack = stk;

	return (EXIT_SUCCESS);
}

/*Checks if a stack_t linked list is in stack or queue mode.*/
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
