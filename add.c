#include "monty.h"
/**
 * monty_add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: nothing 
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    int len, temp;
    len = 0;

    tmp = *stack;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        len++;
    }
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        fclose(inputs.file);
        free(inputs.line);
        monty_free(*stack);
        exit(EXIT_FAILURE);
    }
    tmp = *stack;
    temp = tmp->n + tmp->next->n;
    tmp->next->n = temp;
    *stack = tmp->next;
    free(tmp);
}
