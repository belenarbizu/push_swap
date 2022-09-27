/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:04:55 by barbizu-          #+#    #+#             */
/*   Updated: 2022/09/15 16:51:31 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	change_three(t_stack *a)
{
	if (a->items[0] < a->items[1])
	{
		if (a->items[0] < a->items[2])
			rra(a);
		else
		{
			sa(a);
			ra(a);
		}
	}
}

void	ft_three_stack(t_stack *a)
{
	if (a->items[1] < a->items[2])
	{
		if (a->items[0] > a->items[2])
			sa(a);
		else
		{
			if (a->items[0] < a->items[1])
			{
				sa(a);
				rra(a);
			}
			else
				ra(a);
		}
	}
	else
		change_three(a);
	return ;
}

void	sort_smallest(t_stack *a, int n, int i)
{
	if (n == a->top - 1)
		sa(a);
	else if (n == 0)
		rra(a);
	else if (i < 5)
	{
		while (n < a->top)
		{
			ra(a);
			n++;
		}
	}
	else if (i == 5)
	{
		if (n == 1)
		{
			rra(a);
			rra(a);
		}
		else
		{
			ra(a);
			ra(a);
		}
	}
}

void	pb_smallest(t_stack *a, t_stack *b)
{
	int	i;
	int	n;
	int	num;

	i = 0;
	n = a->top;
	num = top(a);
	while (i < a->top)
	{
		if (num > a->items[i])
		{
			num = a->items[i];
			n = i;
		}
		i++;
	}
	if (n != a->top)
		sort_smallest(a, n, i);
	pb(a, b);
}

void	ft_five_stack(t_stack *a, t_stack *b)
{
	int	i;

	pb_smallest(a, b);
	if (a->top == 3)
		pb_smallest(a, b);
	ft_three_stack(a);
	i = stack_is_sorted(a);
	if (!i)
		sa(a);
	pa(a, b);
	if (b->top == 0)
		pa(a, b);
	return ;
}
