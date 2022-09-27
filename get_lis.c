/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:28:29 by barbizu-          #+#    #+#             */
/*   Updated: 2022/09/22 11:46:14 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	big_num(int *lis, int lenght)
{
	int	max;
	int	i;

	max = lis[lenght];
	i = lenght - 1;
	while (i >= 0)
	{
		if (lis[i] > max)
			max = lis[i];
		i--;
	}
	return (max);
}

int	*lis_num(t_stack *a)
{
	int	*lis;
	int	i;
	int	j;

	lis = (int *)malloc(sizeof(int) * (a->size + 1));
	if (!lis)
		return (0);
	i = a->top - 1;
	while (i >= 0)
	{
		lis[i] = 1;
		j = a->top;
		while (j > i)
		{
			if (a->items[j] < a->items[i] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			j--;
		}
		i--;
	}
	return (lis);
}

int	*get_seq(t_stack *a, int *lis, int lenght)
{
	int	i;
	int	*seq;

	i = 0;
	seq = (int *)malloc(sizeof(int) * (lenght + 1));
	if (!seq)
		return (0);
	while (i <= a->top && lenght > 0)
	{
		if (lis[i] == lenght)
		{
			seq[lenght - 1] = a->items[i];
			lenght--;
		}
		i++;
	}
	return (seq);
}
