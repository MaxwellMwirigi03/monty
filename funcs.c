/*
 * File: funcs.c
 * Auth: Maxwell Mwirigi
 */

#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_numbr);
void monty_pall(stack_t **stack, unsigned int line_numbr);
void monty_pint(stack_t **stack, unsigned int line_numbr);
void monty_pop(stack_t **stack, unsigned int line_numbr);
void monty_swap(stack_t **stack, unsigned int line_numbr);

/*Pushes a value to a stack_t linked list.*/
void monty_push(stack_t **stack, unsigned int line_numbr)
{
	stack_t *tmp, *new_num;
	int i;

	new_num = malloc(sizeof(stack_t));
	if (new_num == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_numbr));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(line_numbr));
			return;
		}
	}
	new_num->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new_num->prev = *stack;
		new_num->next = tmp;
		if (tmp)
			tmp->prev = new_num;
		(*stack)->next = new_num;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new_num->prev = tmp;
		new_num->next = NULL;
		tmp->next = new_num;
	}
}

/*Prints the values of a stack_t linked list.*/
void monty_pall(stack_t **stack, unsigned int line_numbr)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_numbr;
}

/*Prints the top value of a stack_t linked list.*/
void monty_pint(stack_t **stack, unsigned int line_numbr)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_numbr));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/*Removes the top value element of a stack_t linked list.*/
void monty_pop(stack_t **stack, unsigned int line_numbr)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_numbr));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/*Swaps the top two value elements of a stack_t linked list.*/
void monty_swap(stack_t **stack, unsigned int line_numbr)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_numbr, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
