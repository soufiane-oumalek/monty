#ifndef OMARSTACK_H
#define OMARSTACK_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define MAX_LENGTH 256

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


/**
 * struct omarvar - global variabels
 * @val_read: the value readed
 * @line_read: the line readed
 * @file_read: the stream of the file readed
 * Description: the global variables that we used
 */
typedef struct omarvar
{
	int val_read;
	char *line_read;
	FILE *file_read;
}glob;

extern glob var1;


stack_t *pushstack(stack_t **head, int n);

void free_dlistint(stack_t *head);

void getinstruction(instruction_t *instructions);

void push(stack_t **stack, unsigned int line_number);
void error_push(stack_t **stack, unsigned int line_num);

void pall(stack_t **stack, unsigned int line_number);
void error_unknown(stack_t **stack, unsigned int line_num);

void pint(stack_t **stack, unsigned int line_number);
void error_pint(stack_t **stack, unsigned int line_num);

void pop(stack_t **stack, unsigned int line_number);
void error_pop(stack_t **stack, unsigned int line_num);

void swap(stack_t **stack, unsigned int line_number);
void error_swap(stack_t **stack, unsigned int line_num);

void add(stack_t **stack, unsigned int line_number);
void error_add(stack_t **stack, unsigned int line_num);

void nop(stack_t **stack, unsigned int line_number);

void sub(stack_t **stack, unsigned int line_number);
void error_sub(stack_t **stack, unsigned int line_num);

int _isdigit(int c);
int isinteger(char *str);
char *ignore_spaces(char *old_line);


#endif