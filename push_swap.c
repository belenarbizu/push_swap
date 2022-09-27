/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:38:18 by barbizu-          #+#    #+#             */
/*   Updated: 2022/09/22 11:48:58 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	stack_is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->items[i] < a->items[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_add(int size, char **argv, t_stack *a)
{
	int	i;
	int	num;

	i = size - 1;
	while (i > 0)
	{
		num = ft_atoi(argv[i]);
		if (num == 0 && ft_strncmp(argv[i], "0", 1))
		{
			write(1, ERROR, 6);
			free_stack(a, free);
			exit(0);
		}
		if (!push(a, num))
		{
			free_stack(a, free);
			return ;
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		exit(0);
	ft_error(argv);
	a = init(argc - 1);
	b = init(argc - 1);
	ft_add(argc, argv, a);
	i = stack_is_sorted(a);
	if (i)
		exit(0);
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		ft_three_stack(a);
	else if (a->size <= 5)
		ft_five_stack(a, b);
	else
		ft_big_stack(a, b);
	free_stack(a, free);
	free_stack(b, free);
	return (0);
}
