#include "push_swap.h"

void	ra(t_stack *a)
{
	int i;
	int temp;

	i = a->top;
	temp = top(a);
	while (i > 0)
	{
		a->items[i] = a->items[i - 1];
		i--;
	}
	a->items[0] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	int	i;
	int temp;

	i = b->top;
	temp = top(b);
	while (i > 0)
	{
		b->items[i] = b->items[i - 1];
		i--;
	}
	b->items[0] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	int i;
	int temp;

	i = a->top;
	temp = top(a);
	while (i > 0)
	{
		a->items[i] = a->items[i - 1];
		i--;
	}
	a->items[0] = temp;
	i = b->top;
	temp = top(b);
	while (i > 0)
	{
		b->items[i] = b->items[i - 1];
		i--;
	}
	b->items[0] = temp;
	write(1, "rr\n", 3);
}