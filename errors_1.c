/*
 * File: errors_1.c
 * Auth: Maxwell Mwirigi
 */

#include "monty.h"

int short_stack_error(unsigned int line_numbr, char *op);
int div_error(unsigned int line_numbr);
int pop_error(unsigned int line_numbr);
int div_error(unsigned int line_numbr);
int pchar_error(unsigned int line_numbr, char *message);

int pop_error(unsigned int line_numbr)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_numbr);
	return (EXIT_FAILURE);
}

int pint_error(unsigned int line_numbr)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_numbr);
	return (EXIT_FAILURE);
}

int short_stack_error(unsigned int line_numbr, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_numbr, op);
	return (EXIT_FAILURE);
}

int div_error(unsigned int line_numbr)
{
	fprintf(stderr, "L%u: division by zero\n", line_numbr);
	return (EXIT_FAILURE);
}

int pchar_error(unsigned int line_numbr, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_numbr, message);
	return (EXIT_FAILURE);
}
