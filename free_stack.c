#include "push_swap.h"

void    free_stack(t_stack *stack, void (*free_data)(void *))
{
    if (stack || free_data)
        free(stack->items);
}