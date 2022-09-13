#include "push_swap.h"

void    rot_or_rev_a(t_stack *a, t_stack *b, int mean)
{
    int idx;
    int mid;

    (void)b;
    idx = get_idx(a, mean);
    mid = a->size / 2;
    if (idx < mid)
    {
        if (b->size >= 1 && b->items[0] > b->items[b->top])
            rr(a, b);
        else
            ra(a);
    }
    else
    {
        if (b->size >= 1 && b->items[0] > b->items[b->top])
            rrr(a, b);
        else
            rra(a);
    }
}

int get_idx(t_stack *a, int mean)
{
    int i;

    i = 0;
    while (i < a->top)
    {
        if (a->items[i] <= mean)
            return (i);
        i++;
    }
    return (-1);
}

int get_min(t_stack *stack)
{
    int min;
    int i;

    i = stack->top;
    min = stack->items[i];
    while (i >= 0)
    {
        if (min > stack->items[i])
            min = stack->items[i];
        i--;
    }
    return (min);
}

int get_max(t_stack *stack)
{
    int max;
    int i;

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

void    first_pb(t_stack *a, t_stack *b, int *seq, int lis)
{
    int i;
    int j;

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

int longest_sub(t_stack *a, int i)
{
    int lis;
    int j;
    int last_num;

    lis = 1;
    j = i - 1;
    while (j >= 0)
    {
        if (a->items[i] < a->items[j])
        {
            if (j > 0 && a->items[j - 1] < a->items[j] && a->items[j - 1] > a->items[i])
            {
                i = j - 1;
                last_num = a->items[j - 1];
            }
            else
            {
                i = j;
                last_num = a->items[j];
            }
            lis++;
        }
        if (j == 0 && a->items[j] > last_num)
            lis++;
        j--;
    }
    return (lis);
}

int *longest_seq(t_stack *a, int i, int lis)
{
    int *seq;
    int j;
    int m;

    seq = (int *)malloc(sizeof(int) * lis);
    j = i - 1;
    seq[0] = a->items[i];
    m = 1;
    while (j >= 0)
    {
        if (a->items[i] < a->items[j])
        {
            if (j > 0 && a->items[j - 1] < a->items[j] && a->items[j - 1] > a->items[i])
            {
                seq[m] = a->items[j - 1];
                i = j - 1;
            }
            else
            {
                seq[m] = a->items[j];
                i = j;
            }
            m++;
        }
        if (j == 0 && a->items[j] > seq[m - 1])
            seq[m] = a->items[j];
        j--;
    }
    return (seq);
}

int *mov_calc_b(t_stack *b)
{
    int *mov_b;
    int i;
    int j;

    mov_b = (int *)malloc(sizeof(int) * (b->top + 1));

    i = b->top;
    j = 0;
    while (i >= 0)
    {
        if (i >= b->top/2)
            mov_b[i] = j;
        else
            mov_b[i] = -(i + 1);
        j++;
        i--;
    }
    return (mov_b);
}

int pos_greater(int greater, t_stack *a)
{
    int i;
    int moves;

    i = a->top;
    moves = 0;
    while (a->items[i] != greater)
        i--;
    if (i >= a->top/2)
        moves = a->top - i;
    else
        moves = -(i + 1);
    return (moves);
}

int *mov_calc_a(t_stack *a, t_stack *b)
{
    int *mov_a;
    int j;
    int i;
    int greater;

    mov_a = (int *)malloc(sizeof(int) * (b->top + 1));
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

int max_num(int mov_a, int mov_b)
{
    int max;

    max = mov_b;
    if (mov_a > mov_b)
        max = mov_a;
    return (max);
}

int sum_a_b(int mov_a, int mov_b)
{
    int moves;

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

int min_num(int mov_a, int mov_b)
{
    int min;

    min = mov_b;
    if (mov_a < mov_b)
        min = mov_a;
    return (-min);
}

int    choose_best(int *best_num, t_stack *b)
{
    int i;
    int best;
    int pos;

    i = 0;
    best = best_num[i];
    pos = 0;
    while (i <= b->top)
    {
        if (best_num[i] < best)
        {
            best = best_num[i];
            pos = i;
        }
        i++;
    }
    return (pos);
}

void    both_pos(int mov_a, int mov_b, t_stack *a, t_stack *b)
{
    int i;
    int min;
    int dif;

    min = mov_a;
    if (mov_b < mov_a)
        min = mov_b;
    i = 0;
    while (i < min)
    {
        rr(a, b);
        i++;
    }
    i = 0;
    if (mov_b == min)
    {
        dif = mov_a - mov_b;
        while (i < dif)
        {
            ra(a);
            i++;
        }
    }
    else if (mov_a == min)
    {
        dif = mov_b - mov_a;
        while (i < dif)
        {
            rb(b);
            i++;
        }
    }
    pa(a, b);
}

void    pos_a(int mov_a, int mov_b, t_stack *a, t_stack *b)
{
    int i;

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

void    pos_b(int mov_a, int mov_b, t_stack *a, t_stack *b)
{
    int i;

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

void    both_neg(int mov_a, int mov_b, t_stack *a, t_stack *b)
{
    int i;
    int max;
    int dif;

    max = mov_a;
    if (mov_b > mov_a)
        max = mov_b;
    i = 0;
    while (i > max)
    {
        rrr(a, b);
        i--;
    }
    i = 0;
    if (mov_b == max)
    {
        dif = mov_a - mov_b;
        while (i > dif)
        {
            rra(a);
            i--;
        }
    }
    else if (mov_a == max)
    {
        dif = mov_b - mov_a;
        while (i > dif)
        {
            rrb(b);
            i--;
        }
    }
    pa(a, b);
}

void    moves_calculation(t_stack *a, t_stack *b)
{
    int *mov_a;
    int *mov_b;
    int *best_num;
    int i;

    best_num = (int *)malloc(sizeof(int) * (b->top + 1));
    i = b->top;
    while (b->top >= 0)
    {
        mov_b = mov_calc_b(b);
        mov_a = mov_calc_a(a, b);
        i = b->top;
        while (i >= 0)
        {
            if (mov_a[i] >= 0 && mov_b[i] >= 0)
                best_num[i] = max_num(mov_a[i], mov_b[i]);
            else if (mov_a[i] >= 0 && mov_b[i] < 0)
                best_num[i] = sum_a_b(mov_a[i], mov_b[i]);
            else if (mov_a[i] < 0 && mov_b[i] >= 0)
                best_num[i] = sum_a_b(mov_a[i], mov_b[i]);
            else if (mov_a[i] < 0 && mov_b[i] < 0)
                best_num[i] = min_num(mov_a[i], mov_b[i]);
            i--;
        }
        i = choose_best(best_num, b);
        if (mov_a[i] >= 0 && mov_b[i] >= 0)
            both_pos(mov_a[i], mov_b[i], a, b);
        else if (mov_a[i] >= 0 && mov_b[i] < 0)
            pos_a(mov_a[i], mov_b[i], a, b);         
        else if (mov_a[i] < 0 && mov_b[i] >= 0)
            pos_b(mov_a[i], mov_b[i], a, b);
        else if (mov_a[i] < 0 && mov_b[i] < 0)
            both_neg(mov_a[i], mov_b[i], a, b);
    }
}

void    last_moves(t_stack *a)
{
    int big;
    int i;
    int j;

    big = get_max(a);
    i = a->top;
    j = 0;
    while (a->items[i] != big)
        i--;
    if (i >= a->top/2)
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

int big_num(int *lis, int lenght)
{
    int max;
    int i;

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

int *lis_num(t_stack *a)
{
    int *lis;
    int i;
    int j;

    lis = (int *)malloc(sizeof(int) * a->size);
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

int *get_seq(t_stack *a, int *lis, int lenght)
{
    int i;
    int *seq;

    i = 0;
    seq = (int *)malloc(sizeof(int) * lenght);
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

void    ft_big_stack(t_stack *a, t_stack *b)
{
    int *lis;
    int *seq;
    int lenght;

    lis = lis_num(a);
    lenght = big_num(lis, a->top);
    seq = (int *)malloc(sizeof(int) * lenght);
    seq = get_seq(a, lis, lenght);
    first_pb(a, b, seq, lenght);
    moves_calculation(a, b);
    last_moves(a);
} 