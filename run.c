#include "monty.h"p
/**
* _run - _runs the opcode
* @stack: pointer to the linked list - stack
* @line_number: line_line_number
* @file: poiner to monty file
* @line: line line
* Return: nothing
*/
int _run(char *line, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t optc[] = {
				{"push", monty_push}, {"pall", monty_pall}, {"pint", monty_pint},
				{"pop", monty_pop},
				{"swap", monty_swap},
				{"add", monty_add},
				{"nop", monty_nop},
				{"sub", monty_sub},
				{"div", monty_div},
				{"mul", monty_mul},
				{"mod", monty_mod},
				{"pchar", monty_pchar},
				{"pstr", monty_pstr},
				{"rotl", monty_rotl},
				{"rotr", monty_rotr},
				{"queue", monty_queue},
				{"stack", monty_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *opc;

	opc = strtok(line, " \n\t");
	if (opc && opc[0] == '#')
		return (0);
	glinput.arg = strtok(NULL, " \n\t");
	while (optc[i].opcode && opc)
	{
		if (strcmp(opc, optc[i].opcode) == 0)
		{	optc[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (opc && optc[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opc);
		fclose(file);
		free(line);
		monty_free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
