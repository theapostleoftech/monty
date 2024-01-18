#include "monty.h"
/**
 * monty_pall - prints the stack elements
 * @stack: the head of the stack
 * @line_number: not used
 * Return: returns nothing
*/
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *present;

	present = *stack;

	if (present == NULL)
		return;
	while (present)
	{
		printf("%d\n", present->n);
		present = present->next;
	}
	(void)line_number;
}


/**
 * monty_push - adds an element to the stack
 * @stack: the head of the stack
 * @line_number: line number
 * Return: nothing
*/
void monty_push(stack_t **stack, unsigned int line_number)
{
	int n, i, f;

	i = 0;
	f = 0;

	if (inputs.arg)
	{
		if (inputs.arg[0] == '-')
			i++;
		for (; inputs.arg[i] != '\0'; i++)
		{
			if (inputs.arg[i] > 9 || inputs.arg[i] < 0)
				f = 1;
		}
		if (f == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(inputs.file);
			free(inputs.line);
			monty_free(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(inputs.file);
		free(inputs.line);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(inputs.arg);


}

