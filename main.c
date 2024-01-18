#include "monty.h"
/**
 * main - monty code interpreter
 * @argc: agrgument count
 * @argv: argument vector
 * 
 * Return: zero if successful
*/
int main(int argc, char *argv[])
{
    char *line = NULL;
    FILE *file;
    size_t len = 0;
    size_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (read_line > 0)
    {
        read_line = getline(&line, &len, file);
        line_number++;
    }
    free(line);
    fclose(file);
return (0);
}
