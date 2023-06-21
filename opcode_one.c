#include "monty.h"

/**
 * _push - adds an element to the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *count_args;
	int val;
	stack_t *insert = malloc(sizeof(stack_t));

	if (insert == NULL)
	{
		free(insert);
		fprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	count_args = strtok(NULL, " \n");
	if (count_args == NULL)
	{
		fprintf(2, "L%d: usage push integer", line_number);
		exit(EXIT_FAILURE);
	}

	val = atoi(count_args);

	insert->n = val;
	insert->prev = NULL;
	insert->next = (*stack);

	if ((*stack) != NULL)
		(*stack)->prev = insert;

	(*stack) = insert;
}

/**
 * _pall - prints all the values on the stack, starting from the top
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *start = (*stack);

	(void)line_number;

	while (start != NULL)
	{
		printf("%d\n", start->n);
		start = start->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *start = *stack;

	if (start == NULL)
	{
		fprintf(2, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", start->n);

}

/**
 * _pop - removes the value at the top of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *start = *stack;

	if (*stack == NULL)
	{
		fprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = start->next;

	if (*stack != NULL)
		start->next->prev = NULL;

	free(start);
}

/**
 * _swap - swaps the top 2 values of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;
	int hold;

	if (*stack == NULL || tmp == NULL)
	{
		fprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	hold = (*stack)->n;
	(*stack)->n = tmp->n;
	tmp->n = hold;
}
