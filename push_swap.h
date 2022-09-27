/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:22:55 by barbizu-          #+#    #+#             */
/*   Updated: 2022/09/15 16:52:08 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR "Error\n"

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int	size;
	int	top;
	int	*items;
}				t_stack;

t_stack	*init(int size);
int		push(t_stack *stack, int items);
int		top(t_stack *stack);
int		pop(t_stack *stack);

int		ft_size(char **tab);
void	ft_duplicate(char **tab);
void	ft_error(char **tab);
void	free_stack(t_stack *stack, void (*free_data)(void *));

int		stack_is_sorted(t_stack *a);
void	ft_add(int size, char **argv, t_stack *a);

void	change_three(t_stack *a);
void	ft_three_stack(t_stack *a);
void	sort_smallest(t_stack *a, int n, int i);
void	pb_smallest(t_stack *a, t_stack *b);
void	ft_five_stack(t_stack *a, t_stack *b);

int		get_max(t_stack *stack);
void	first_pb(t_stack *a, t_stack *b, int *seq, int lis);
void	moves_calculation(t_stack *a, t_stack *b);
void	last_moves(t_stack *a);
void	ft_big_stack(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

int		big_num(int *lis, int lenght);
int		*lis_num(t_stack *a);
int		*get_seq(t_stack *a, int *lis, int lenght);

int		max_num(int mov_a, int mov_b);
int		sum_a_b(int mov_a, int mov_b);
int		min_num(int mov_a, int mov_b);
int		choose_best(int *best_num, t_stack *b);

int		best_num(int mov_a, int mov_b);
void	both_pos(int mov_a, int mov_b, t_stack *a, t_stack *b);
void	pos_a(int mov_a, int mov_b, t_stack *a, t_stack *b);
void	pos_b(int mov_a, int mov_b, t_stack *a, t_stack *b);
void	both_neg(int mov_a, int mov_b, t_stack *a, t_stack *b);

void	do_moves(int mov_a, int mov_b, t_stack *a, t_stack *b);
int		*mov_calc_b(t_stack *b);
int		pos_greater(int greater, t_stack *a);
int		*mov_calc_a(t_stack *a, t_stack *b);
#endif
