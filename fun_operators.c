#include "monty.h"

/**
* fun_operators - constructor function
* @operation: operation
* @top: pointer to struct
* @Nlinea: number of line by error
*
* Return: 0
*/
int fun_operators(char *operation, stack_t **top, int Nlinea)
{
	int i = 0, flag = 0;

	instruction_t f_ope[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL},
	};
	while (f_ope[i].opcode != NULL)
	{
		if (strcmp(operation, f_ope[i].opcode) == 0)
		{
			f_ope[i].f(top, Nlinea);
			flag = 1;
		}
		i++;
	}
	if (flag != 1)
		funErrorNoOPCODE(Nlinea, "unknown instruction", operation);
	return (0);
}

/**
* _pall - function that print all stack
* @stack: stack
* @line_number: number of line by error
*
* Return: 0
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (*stack == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
* _push - function that add value to stack
* @top: pointer to struct
* @line_number: number of line by error
*
* Return: 0
*/
void _push(stack_t **top, unsigned int line_number)
{
	stack_t *neW = NULL;
	(void)line_number;

	neW = malloc(sizeof(stack_t));
	if (neW == NULL)
	{
		funErrorGeneric("Error: malloc failed");
	}
	neW->n = 0;
	neW->prev = NULL;
	if (*top == NULL)
	{
		neW->next = NULL;
		*top = neW;
	}
	else
	{
		neW->next = *top;
		(*top)->prev = neW;
		*top = neW;
	}
}
