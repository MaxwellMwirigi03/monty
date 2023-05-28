/*
 * File: funcs_3.c
 * Auth: Maxwell Mwirigi
 */

#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_numbr);
void monty_rotr(stack_t **stack, unsigned int line_numbr);
void monty_stack(stack_t **stack, unsigned int line_numbr);
void monty_queue(stack_t **stack, unsigned int line_numbr);

/*Rotates the top value of a stack_t linked list to the bottom.*/
void monty_rotl(stack_t **stack, unsigned int line_numbr)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_numbr;
}

/*Rotates the bottom value of a stack_t linked list to the top.*/
void monty_rotr(stack_t **stack, unsigned int line_numbr)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_numbr;
}

/*Converts a queue to a stack.*/
void monty_stack(stack_t **stack, unsigned int line_numbr)
{
	(*stack)->n = STACK;
	(void)line_numbr;
}

/*Converts a stack to a queue.*/
void monty_queue(stack_t **stack, unsigned int line_numbr)
{
	(*stack)->n = QUEUE;
	(void)line_numbr;
}
