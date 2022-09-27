/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:11:54 by barbizu-          #+#    #+#             */
/*   Updated: 2022/09/14 18:12:44 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_stack(t_stack *stack, void (*free_data)(void *))
{
	if (stack)
	{
		free_data(stack->items);
		free_data(stack);
	}
}

int	ft_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_duplicate(char **tab)
{
	int	pos;
	int	i;

	pos = 1;
	while (tab[pos])
	{
		i = pos + 1;
		while (tab[i])
		{
			if (!ft_strncmp(tab[pos], tab[i], 11))
			{
				write(1, ERROR, 6);
				exit(0);
			}
			i++;
		}
		pos++;
	}
}

void	ft_error(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '-')
				j++;
			if (!ft_isdigit(tab[i][j]))
			{
				write(1, ERROR, 6);
				exit(0);
			}
			j++;
		}
		i++;
	}
	ft_duplicate(tab);
}
