#include "monty.h"

/**
 * main - function that
 * @argc: nothing
 * @argv: char name
 * Return: int 0 is success exit
 */

int main(int argc, char *argv[])
{
	FILE *filedesc;
	char *operation, *operation2, *line_buf = NULL;
	size_t sizeBuffer = 1024;
	int Nlinea = 1;
	stack_t *top = NULL;

	if (argc > 2 || argc == 1)
		funErrorGeneric("USAGE: monty file");
	filedesc = fopen(argv[1], "r");
	if (filedesc == NULL)
		funErrorGenericCHAR("Error: Can't open file", argv[1]);
	while (getline(&line_buf, &sizeBuffer, filedesc) != EOF)
	{
		operation = strtok(line_buf, " \r\n\t");
		if (operation == NULL)
		{
			Nlinea += 1;
			continue;
		}
		fun_operators(operation, &top, Nlinea);
		operation2 = strtok(NULL, " \r\n\t");
		if ((strcmp(operation, "push") == 0))
		{
			if (operation2 == NULL || is_number(operation2) == -1)
			{
				funErrorGenericINT(Nlinea, "usage: push integer");
			}
			top->n = atoi(operation2);
		}
		Nlinea += 1;
	}
	fclose(filedesc);
	free(line_buf);
	free_stack(top);
	return (0);
}
