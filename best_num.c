/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:16:22 by barbizu-          #+#    #+#             */
/*   Updated: 2022/09/22 12:02:43 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	best_num(int mov_a, int mov_b)
{
	int	num;

	num = 0;
	if (mov_a >= 0 && mov_b >= 0)
		num = max_num(mov_a, mov_b);
	else if (mov_a >= 0 && mov_b < 0)
		num = sum_a_b(mov_a, mov_b);
	else if (mov_a < 0 && mov_b >= 0)
		num = sum_a_b(mov_a, mov_b);
	else if (mov_a < 0 && mov_b < 0)
		num = min_num(mov_a, mov_b);
	return (num);
}

void	both_pos(int mov_a, int mov_b, t_stack *a, t_stack *b)
{
	int	i;
	int	min;
	int	dif;

	min = mov_a;
	if (mov_b < mov_a)
		min = mov_b;
	i = 0;
	while (i++ < min)
		rr(a, b);
	i = 0;
	if (mov_b == min)
	{
		dif = mov_a - mov_b;
		while (i++ < dif)
			ra(a);
	}
	else if (mov_a == min)
	{
		dif = mov_b - mov_a;
		while (i++ < dif)
			rb(b);
	}
	pa(a, b);
}

void	pos_a(int mov_a, int mov_b, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < mov_a)
	{
		ra(a);
		i++;
	}
	i = 0;
	while (i > mov_b)
	{
		rrb(b);
		i--;
	}
	pa(a, b);
}

void	pos_b(int mov_a, int mov_b, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i > mov_a)
	{
		rra(a);
		i--;
	}
	i = 0;
	while (i < mov_b)
	{
		rb(b);
		i++;
	}
	pa(a, b);
}

void	both_neg(int mov_a, int mov_b, t_stack *a, t_stack *b)
{
	int	i;
	int	max;
	int	dif;

	max = max_num(mov_a, mov_b);
	i = 0;
	while (i-- > max)
		rrr(a, b);
	i = 0;
	if (mov_b == max)
	{
		dif = mov_a - mov_b;
		while (i-- > dif)
			rra(a);
	}
	else if (mov_a == max)
	{
		dif = mov_b - mov_a;
		while (i-- > dif)
			rrb(b);
	}
	pa(a, b);
}
