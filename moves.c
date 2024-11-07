/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:32:55 by barbizu-          #+#    #+#             */
/*   Updated: 2022/09/15 16:37:55 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	do_moves(int mov_a, int mov_b, t_stack *a, t_stack *b)
{
	if (mov_a >= 0 && mov_b >= 0)
		both_pos(mov_a, mov_b, a, b);
	else if (mov_a >= 0 && mov_b < 0)
		pos_a(mov_a, mov_b, a, b);
	else if (mov_a < 0 && mov_b >= 0)
		pos_b(mov_a, mov_b, a, b);
	else if (mov_a < 0 && mov_b < 0)
		both_neg(mov_a, mov_b, a, b);
}

int	*mov_calc_b(t_stack *b)
{
	int	*mov_b;
	int	i;
	int	j;

	mov_b = (int *)malloc(sizeof(int) * (b->top + 1));
	if (!mov_b)
		return (0);
	i = b->top;
	j = 0;
	while (i >= 0)
	{
		if (i >= (b->top / 2))
			mov_b[i] = j;
		else
			mov_b[i] = -(i + 1);
		j++;
		i--;
	}
	return (mov_b);
}

int	pos_greater(int greater, t_stack *a)
{
	int	i;
	int	moves;

	i = a->top;
	moves = 0;
	while (a->items[i] != greater)
		i--;
	if (i >= (a->top / 2))
		moves = a->top - i;
	else
		moves = -(i + 1);
	return (moves);
}

int	*mov_calc_a(t_stack *a, t_stack *b)
{
	int	*mov_a;
	int	j;
	int	i;
	int	greater;

	mov_a = malloc(sizeof(int) * (b->top + 1));
	if (!mov_a)
		return (0);
	i = b->top;
	while (i >= 0)
	{
		j = a->top;
		greater = get_max(a);
		while (j >= 0)
		{
			if (a->items[j] > b->items[i] && a->items[j] < greater)
				greater = a->items[j];
			j--;
		}
		mov_a[i] = pos_greater(greater, a);
		if (b->items[i] > greater)
			mov_a[i] += 1;
		i--;
	}
	return (mov_a);
}
