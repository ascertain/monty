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
	stack_t *insert;

	count_args = strtok(NULL, " \n");
	if (count_args == NULL)
	{
		fprintf(stderr, "L%d: usage push integer", line_number);
		exit(EXIT_FAILURE);
	}

	val = atoi(count_args);

	insert = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		insert->n = val;
		insert->prev = NULL;
		insert->next = NULL;
		(*stack) = insert;
	}
	else
	{
		insert->n = val;
		insert->prev = NULL;
		insert->next = (*stack);
		(*stack) = insert;
	}
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
	stack_t *start;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	start = *stack;

	printf("%d\n", start->n);

}

/**
 * _pop - removes the value at the top of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *start;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	start = *stack;

	*stack = (*stack)->next;

	free(start);
}

/**
 * _swap - swaps the top 2 values of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int hold;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;

	hold = (*stack)->n;
	(*stack)->n = tmp->n;
	tmp->n = hold;
}
