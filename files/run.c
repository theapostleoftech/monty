#include "monty.h"
/**
 * _run - runs the opcode
 * @stack: the stack
 * @line_number: line number
 * @file: monty file pointer
 * @line: line
 * Return: nothing
 */
int _run(char *line, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t options[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
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
	inputs.arg = strtok(NULL, " \n\t");
	while (options[i].opcode && opc)
	{
		if (strcmp(opc, options[i].opcode) == 0)
		{
			options[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (opc && options[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opc);
		fclose(file);
		free(line);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);

}

