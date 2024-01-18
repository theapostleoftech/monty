#include "monty.h"

global_t vglo;

/**
 * free_vglo - frees the global variables
 *
 * Return: no return
 */
void free_vglo(void)
{
	free_dlistint(vglo.head);
	free(vglo.buffer);
	fclose(vglo.fd);
}

/**
 * start_vglo - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_vglo(FILE *fd)
{
	vglo.lifo = 1;
	vglo.cont = 1;
	vglo.arg = NULL;
	vglo.head = NULL;
	vglo.fd = fd;
	vglo.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
<<<<<<< HEAD:main.c
	FILE *fd;

	if (argc == 1 || argc > 2)
=======
	char *line;
	FILE *file;
	size_t len = 0;
	size_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
>>>>>>> b0a29fd31ff29f9e1a3c5f6e1c8b513d2d56b5b7:files/main.c
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
<<<<<<< HEAD:main.c

	fd = fopen(argv[1], "r");

	if (fd == NULL)
=======
	file = fopen(argv[1], "r");
	inputs.file = file;
	if (!file)
>>>>>>> b0a29fd31ff29f9e1a3c5f6e1c8b513d2d56b5b7:files/main.c
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_vglo(fd);
	nlines = getline(&vglo.buffer, &size, fd);
	while (nlines != -1)
	{
<<<<<<< HEAD:main.c
		lines[0] = _strtoky(vglo.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
=======
		line = NULL;
		read_line = getline(&line, &len, file);
		inputs.line = line;
		line_number++;
		if (read_line > 0)
>>>>>>> b0a29fd31ff29f9e1a3c5f6e1c8b513d2d56b5b7:files/main.c
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vglo.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_vglo();
				exit(EXIT_FAILURE);
			}
			vglo.arg = _strtoky(NULL, " \t\n");
			f(&vglo.head, vglo.cont);
		}
		nlines = getline(&vglo.buffer, &size, fd);
		vglo.cont++;
	}

	free_vglo();

	return (0);
}
