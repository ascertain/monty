#include "monty.h"

/**
 * _add - adds the top 2 values of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *start;
	int hold;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		start = *stack;

		hold = start->n + start->next->n;

		start->next->n = hold;
		*stack = start->next;
		free(start);
	}
}

/**
 * _nop - doesn’t do anything.
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}
