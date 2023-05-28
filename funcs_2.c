/*
 * File: funcs_2.c
 * Auth: Maxwell Mwirigi
 */

#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_numbr);
void monty_pchar(stack_t **stack, unsigned int line_numbr);
void monty_pstr(stack_t **stack, unsigned int line_numbr);

/*Does absolutely nothing for the Monty opcode 'nop'.*/
void monty_nop(stack_t **stack, unsigned int line_numbr)
{
	(void)stack;
	(void)line_numbr;
}

/*Prints the character in the top value node of a stack_t linked list.*/
void monty_pchar(stack_t **stack, unsigned int line_numbr)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_numbr, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_numbr,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/*Prints the string contained in a stack_t linked list.*/
void monty_pstr(stack_t **stack, unsigned int line_numbr)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_numbr;
}
