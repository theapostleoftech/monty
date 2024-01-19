#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

glinput_t glinput = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *line;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	glinput.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line = NULL;
		read_line = getline(&line, &size, file);
		glinput.line = line;
		line_number++;
		if (read_line > 0)
		{
			_run(line, &stack, line_number, file);
		}
		free(line);
	}
	monty_free_stack(stack);
	fclose(file);
return (0);
}
