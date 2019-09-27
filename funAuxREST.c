#include "monty.h"
/**
* _add - adds the top two elements of the stack.
* @stack: Linked list
* @line_number: Int value
* Return: Void
*/
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	if (!(*stack) || !(*stack)->next)
	{
		funErrorGenericINT(line_number, "can't add, stack too short");
	}
	node1 = (*stack);
	node2 = node1->next;
	node2->n += node1->n;
	_pop(stack, line_number);
}

/**
* _nop - doesnt do anything.
* @stack: Linked list
* @line_number: Int value
* Return: Void
*/
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}

/**
* _sub - subtracts the top element of the stack from the second.
* @stack: Linked list
* @line_number: Int value
* Return: Void
*/
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	if (!(*stack) || !(*stack)->next)
	{
		funErrorGenericINT(line_number, "can't sub, stack too short");
	}
	node1 = (*stack);
	node2 = node1->next;
	node2->n = node2->n - node1->n;
	_pop(stack, line_number);
}

/**
* _div - subtracts the top element of the stack from the second.
* @stack: Linked list
* @line_number: Int value
* Return: Void
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	if (!(*stack) || !(*stack)->next)
	{
		funErrorGenericINT(line_number, "can't div, stack too short");
	}
	node1 = (*stack);
	node2 = node1->next;
	if (node1->n == 0)
	{
		funErrorGenericINT(line_number, "division by zero");
	}
	node2->n = node2->n / node1->n;
	_pop(stack, line_number);
}
/**
* _mul - multiplies the second top element of the stack with the top.
* @stack: Linked list
* @line_number: Int value
* Return: Void
*/
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	if (!(*stack) || !(*stack)->next)
	{
		funErrorGenericINT(line_number, "can't mul, stack too short");
	}
	node1 = (*stack);
	node2 = node1->next;
	node2->n = node2->n * node1->n;
	_pop(stack, line_number);
}
