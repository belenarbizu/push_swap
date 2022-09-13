#include "push_swap.h"

t_stack	*init(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->size = size;
	stack->top = -1;
	stack->items = (int *)malloc(sizeof(int) * size);
	if (!stack->items)
	{
		free(stack);
		return (0);
	}
	return (stack);
}

int	push(t_stack *stack, int items)
{
	if (!stack || (stack->top + 1 == stack->size))
		return (0);
	stack->top++;
	stack->items[stack->top] = items;
	return (1);
}

int	top(t_stack *stack)
{
	return (stack->items[stack->top]);
}

int	pop(t_stack *stack)
{
	int	item;

	if (!stack)
		return (0);
	item = top(stack);
	stack->items[stack->top] = 0;
	stack->top--;
	return (item);
}
