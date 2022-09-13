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
	int *items;
}				t_stack;

t_stack	*init(int size);
int		push(t_stack *stack, int items);
int		top(t_stack *stack);
int		pop(t_stack *stack);

int		ft_size(char **tab);
void	ft_duplicate(char **tab);
void	ft_error(char **tab);

void    free_stack(t_stack *stack, void (*free_data)(void *));

int		stack_is_sorted(t_stack *a);
void    ft_add(int size, char **argv, t_stack *a);

void	ft_three_stack(t_stack *a);
void    sort_smallest(t_stack *a, int n, int i);
void    pb_smallest(t_stack *a, t_stack *b);
void	ft_five_stack(t_stack *a, t_stack *b);
void    ft_ten_stack(t_stack *a, t_stack *b);
void    ft_big_stack(t_stack *a, t_stack *b);

void    rot_or_rev_a(t_stack *a, t_stack *b, int mean);
int		get_min(t_stack *stack);
int		get_idx(t_stack *a, int mean);

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
#endif