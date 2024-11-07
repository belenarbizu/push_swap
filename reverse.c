/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:13:10 by barbizu-          #+#    #+#             */
/*   Updated: 2022/09/14 18:15:17 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_stack *a)
{
	int	i;
	int	temp;

	i = 0;
	temp = a->items[i];
	while (i < a->top)
	{
		a->items[i] = a->items[i + 1];
		i++;
	}
	a->items[a->top] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	int	i;
	int	temp;

	i = 0;
	temp = b->items[i];
	while (i < b->top)
	{
		b->items[i] = b->items[i + 1];
		i++;
	}
	b->items[b->top] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	int	i;
	int	temp;

	i = 0;
	temp = a->items[i];
	while (i < a->top)
	{
		a->items[i] = a->items[i + 1];
		i++;
	}
	a->items[a->top] = temp;
	i = 0;
	temp = b->items[i];
	while (i < b->top)
	{
		b->items[i] = b->items[i + 1];
		i++;
	}
	b->items[b->top] = temp;
	write(1, "rrr\n", 4);
}
