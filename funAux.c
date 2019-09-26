#include "monty.h"
/**
* is_number - return -1 if is number
* @operation2: *char with second parametr
* Return: int
*/
int is_number(char *operation2)
{
	int k = 0;

	while (operation2[k] != '\0')
	{
		if (isdigit(operation2[k]) == 0 && operation2[k] != 45)
		{
			return (-1);
		}
		k++;
	}
	return (1);
}

/**
* free_stack - Free the list
* @stack: The start of the list
*/
void free_stack(stack_t *stack)
{
	stack_t *current, *next;

	current = stack;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
* _pint - Prints the value at the top of the stack
* @stack: Linked list
* @line_number: Int value
* Return: Void
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (!current)
	{
		funErrorGenericINT(line_number, "can't pint, stack empty");
	}
	printf("%d\n", current->n);
}

/**
* _pop - Prints the value at the top of the stack
* @stack: Linked list
* @line_number: Int value
* Return: Void
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (!h)
	{
		funErrorGenericINT(line_number, "can't pop an empty stack");

	}
	h = (*stack)->next;
	free(*stack);
	*stack = h;
}

/**
* _swap - swaps the top two elements of the stack.
* @stack: Linked list
* @line_number: Int value
* Return: Void
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;
	int n;

	if (!(*stack) || !(*stack)->next)
	{
		funErrorGenericINT(line_number, "can't swap, stack too short");
	}

	node1 = (*stack);
	node2 = node1->next;
	n = node1->n;
	node1->n = node2->n;
	node2->n = n;
}
