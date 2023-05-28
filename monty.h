#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);

/* OPCODE FUNCTIONS */
void monty_push(stack_t **stack, unsigned int line_numbr);
void monty_pall(stack_t **stack, unsigned int line_numbr);
void monty_pint(stack_t **stack, unsigned int line_numbr);
void monty_pop(stack_t **stack, unsigned int line_numbr);
void monty_swap(stack_t **stack, unsigned int line_numbr);
void monty_add(stack_t **stack, unsigned int line_numbr);
void monty_nop(stack_t **stack, unsigned int line_numbr);
void monty_sub(stack_t **stack, unsigned int line_numbr);
void monty_div(stack_t **stack, unsigned int line_numbr);
void monty_mul(stack_t **stack, unsigned int line_numbr);
void monty_mod(stack_t **stack, unsigned int line_numbr);
void monty_pchar(stack_t **stack, unsigned int line_numbr);
void monty_pstr(stack_t **stack, unsigned int line_numbr);
void monty_rotl(stack_t **stack, unsigned int line_numbr);
void monty_rotr(stack_t **stack, unsigned int line_numbr);
void monty_stack(stack_t **stack, unsigned int line_numbr);
void monty_queue(stack_t **stack, unsigned int line_numbr);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);
int usage_error(void);
int malloc_error(void);
int main(int argc, char **argv);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int pop_error(unsigned int line_numbr);
int pint_error(unsigned int line_numbr);
int short_stack_error(unsigned int line_numbr, char *op);
int div_error(unsigned int line_numbr);
int pchar_error(unsigned int line_numbr, char *message);

#endif /* __MONTY_H__ */
