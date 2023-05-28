/*
 * File: funcs_1.c
 * Auth: Maxwell Mwirigi
 */

#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_numbr);
void monty_sub(stack_t **stack, unsigned int line_numbr);
void monty_div(stack_t **stack, unsigned int line_numbr);
void monty_mul(stack_t **stack, unsigned int line_numbr);
void monty_mod(stack_t **stack, unsigned int line_numbr);

/*Adds the top two values of a stack_t linked list.*/
void monty_add(stack_t **stack, unsigned int line_numbr)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_numbr, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_numbr);
}

/*Subtracts the second value from the top of a stack_t linked list by the top value.*/
void monty_sub(stack_t **stack, unsigned int line_numbr)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_numbr, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_numbr);
}

/*Divides the second value from the top of a stack_t linked list by the top value.*/
void monty_div(stack_t **stack, unsigned int line_numbr)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_numbr, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_numbr));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_numbr);
}

/*Multiplies the second value from the top of a stack_t linked list by the top value.*/
void monty_mul(stack_t **stack, unsigned int line_numbr)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_numbr, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_numbr);
}

/*Computes the modulus of the second value from the top of a stack_t linked list by the top value.*/
void monty_mod(stack_t **stack, unsigned int line_numbr)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_numbr, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_numbr));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_numbr);
}
