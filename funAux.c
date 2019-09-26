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
