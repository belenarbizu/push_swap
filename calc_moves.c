/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:24:53 by barbizu-          #+#    #+#             */
/*   Updated: 2022/09/14 18:28:04 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	max_num(int mov_a, int mov_b)
{
	int	max;

	max = mov_b;
	if (mov_a > mov_b)
		max = mov_a;
	return (max);
}

int	sum_a_b(int mov_a, int mov_b)
{
	int	moves;

	moves = 0;
	if (mov_a < 0)
	{
		mov_a = -mov_a;
		moves = mov_a + mov_b;
	}
	else if (mov_b < 0)
	{
		mov_b = -mov_b;
		moves = mov_a + mov_b;
	}
	return (moves);
}

int	min_num(int mov_a, int mov_b)
{
	int	min;

	min = mov_b;
	if (mov_a < mov_b)
		min = mov_a;
	return (-min);
}

int	choose_best(int *best_num, t_stack *b)
{
	int	i;
	int	best;
	int	pos;

	i = b->top;
	best = best_num[i];
	pos = b->top;
	while (i >= 0)
	{
		if (best_num[i] < best)
		{
			best = best_num[i];
			pos = i;
		}
		i--;
	}
	return (pos);
}
