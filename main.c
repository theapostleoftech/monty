#include "monty.h"
/**
 * main - monty interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: zero on success 
 */
input_t inputs = {NULL, NULL, NULL, 0};
int main(int argc, char *argv[])
{
    char *line = NULL;
    FILE *file;
    size_t len = 0;
    size_t read_line = 0;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    inputs.file = file;
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (read_line > 0)
    {
        read_line = getline(&line, &len, file);
        inputs.line = line;
        line_number++;
        if (read_line > 0)
        {
            _run(line, &stack, line_number, file);
        }
        free(line);
    }
    monty_free(stack);
    fclose(file);
return (EXIT_SUCCESS);
}
