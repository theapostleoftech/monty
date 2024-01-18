#include "monty.h"
/**
 * monty_pint - prints the value at the top of stack
 * @stack: pointer to the top of stack
 * @line_number: line number
 * Return: nothing
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        fclose(inputs.file);
        free(inputs.line);
        monty_free(*stack);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}
