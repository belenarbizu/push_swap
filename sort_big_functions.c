/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:40:56 by barbizu-          #+#    #+#             */
/*   Updated: 2022/09/22 12:09:12 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_max(t_stack *stack)
{
	int	max;
	int	i;

	i = stack->top;
	max = stack->items[i];
	while (i >= 0)
	{
		if (max < stack->items[i])
			max = stack->items[i];
		i--;
	}
	return (max);
}

void	first_pb(t_stack *a, t_stack *b, int *seq, int lis)
{
	int	i;
	int	j;

	i = a->top;
	j = 0;
	while (j < lis)
	{
		if (a->items[i] != seq[j])
			pb(a, b);
		else
		{
			ra(a);
			i++;
			j++;
		}
		if (j == lis && a->top != lis - 1)
		{
			while (a->top != lis - 1)
				pb(a, b);
		}
		i--;
	}
}

void	moves_calculation(t_stack *a, t_stack *b)
{
	int	*mov_a;
	int	*mov_b;
	int	*num;
	int	i;

	num = (int *)malloc(sizeof(int) * (b->top + 1));
	while (b->top >= 0)
	{
		mov_b = mov_calc_b(b);
		mov_a = mov_calc_a(a, b);
		i = b->top + 1;
		while (--i >= 0)
			num[i] = best_num(mov_a[i], mov_b[i]);
		i = choose_best(num, b);
		do_moves(mov_a[i], mov_b[i], a, b);
		free(mov_a);
		free(mov_b);
	}
	free(num);
}

void	last_moves(t_stack *a)
{
	int	big;
	int	i;
	int	j;

	big = get_max(a);
	i = a->top;
	j = 0;
	while (a->items[i] != big)
		i--;
	if (i >= (a->top / 2))
	{
		while (j < (a->top - i + 1))
		{
			ra(a);
			j++;
		}
	}
	else
	{
		while (j > -i)
		{
			rra(a);
			j--;
		}
	}
}

void	ft_big_stack(t_stack *a, t_stack *b)
{
	int	*lis;
	int	*seq;
	int	lenght;

	lis = lis_num(a);
	lenght = big_num(lis, a->top);
	seq = get_seq(a, lis, lenght);
	first_pb(a, b, seq, lenght);
	moves_calculation(a, b);
	last_moves(a);
	free(lis);
	free(seq);
}
