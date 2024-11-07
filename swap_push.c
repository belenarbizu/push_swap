/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:03:01 by barbizu-          #+#    #+#             */
/*   Updated: 2022/09/14 18:03:59 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	temp = 0;
	if (a->top >= 0)
	{
		temp = a->items[a->top];
		a->items[a->top] = a->items[a->top - 1];
		a->items[a->top - 1] = temp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	temp;

	temp = 0;
	if (b->top >= 0)
	{
		temp = b->items[b->top];
		b->items[b->top] = b->items[b->top - 1];
		b->items[b->top - 1] = temp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	temp = 0;
	if (a->top >= 0)
	{
		temp = a->items[a->top];
		a->items[a->top] = a->items[a->top - 1];
		a->items[a->top - 1] = temp;
	}
	if (b->top >= 0)
	{
		temp = b->items[b->top];
		b->items[b->top] = b->items[b->top - 1];
		b->items[b->top - 1] = temp;
	}
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	i = push(a, pop(b));
	if (!i)
		return ;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	i = push(b, pop(a));
	if (!i)
		return ;
	write(1, "pb\n", 3);
}
