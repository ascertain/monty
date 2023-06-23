#include "monty.h"

/**
 * main - entry point
 * @argc: number of argument
 * @argv: arguments
 * Description: entry point for stack options and execution
 * Return: 0
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	instruction_t pair[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};
	FILE *m;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	m = fopen(argv[1], "r");
	if (m == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_parse_exec(m, pair, &stack);

	fclose(m);

	/* clean up stack after file is closed*/
	while (stack != NULL)
	{
		stack_t *tmp = stack;

		stack = stack->next;
		free(tmp);
	}
	return (0);
}

/**
 * read_parse_exec - execute fuction
 * @file: file to read from
 * @pair: opcode and function
 * @stack: top of stack
 * Description: reads from giving file, search for function pair in pair[]
 * and executes
 */
void read_parse_exec(FILE *file, instruction_t *pair, stack_t **stack)
{
	char inpt[NUM];
	unsigned int line_number = 1;

	while (fgets(inpt, sizeof(inpt), file))
	{
		char *opcode_tok;
		int size;

		size = strlen(inpt);
		if (size > 0 && inpt[size - 1] == '\n')
			inpt[size - 1] = '\0';

		opcode_tok = strtok(inpt, " $\n");
		if (opcode_tok != NULL)
		{
			instruction_t *start = pair;

			while (start->opcode != NULL)
			{
				if (strcmp(start->opcode, opcode_tok) == 0)
				{
					start->f(stack, line_number);
					break;
				}
				start++;
			}
			if (start->opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s", line_number, start->opcode);
				exit(EXIT_FAILURE);
			}
		}

		line_number++;
	}
}

