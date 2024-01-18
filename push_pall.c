#include "monty.h"
/**
 * monty_pall - prints the stack elements
 * @stack: the head of the stack
 * @line_number: not used
 * 
 * Return: returns nothing
*/
void monty_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *present;
    present = *stack;

    if (present == NULL)
    {
        return;
    }
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
 * 
 * Return: nothing
*/
void monty_push(stack_t **stack, unsigned int line_number)
{
    
}