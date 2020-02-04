//
// Created by Mandi Burnette on 04/02/2020.
//

#include "LIBFT/libft.h"
#include "LIBFT/dlist.h"

//      перекидываем все что есть в первом стеке во второй
void    push_all_stack(t_dlist **stack_b, t_dlist **stack_a)
{
    while ((*stack_b))
        oper_p(&(*stack_a), &(*stack_b));
}

//  сортируем Б еще на две части и перекидываем их в А
void    sort_b_push_to_a(t_dlist **stack_b, t_dlist **stack_a)
{
    t_dlist *max;
    t_dlist *min;
    int all_num;
    int count;

    max = find_max((*stack_b));
    min = find_min((*stack_b));
    all_num = ft_dlistlen((*stack_b));
    count = 0;

    while ((*stack_b) && count < all_num)
    {
        if ((*stack_b)->num > (max->num - min->num) / 3) // для случая в 50 - если между 16 и 25 (больше 16)
            oper_p(&(*stack_a), &(*stack_b));
        else
            oper_r(&(*stack_b));
        count++;
    }
    push_all_stack(stack_b, stack_a);
}

// перекидываем из стека а в б значения меньше половины от максимума
void    first_sort(t_dlist **stack_a, t_dlist **stack_b)
{
    t_dlist *max;
    t_dlist *min;
    int all_num;
    int count;

    max = find_max((*stack_a));
    min = find_min((*stack_a));

    all_num = ft_dlistlen((*stack_a));
    count = 0;

    while ((*stack_a) && count < all_num)
    {
        if ((*stack_a)->num < (max->num - min->num) / 2 + 1)
            oper_p(&(*stack_b), &(*stack_a));
        else
            oper_r(&(*stack_a));
        count++;
    }
}

// перекидываем из Б в А значения сначала побольше, затем поменьше
void    second_sort(t_dlist **stack_a, t_dlist **stack_b)
{
    t_dlist *max;
    t_dlist *min;
    int all_num;
    int count;

    max = find_max((*stack_b));
    min = find_min((*stack_b));
    all_num = ft_dlistlen((*stack_b));
    count = 0;

    while ((*stack_b) && count < all_num)
    {
        if ((*stack_b)->num > (max->num - min->num) / 2) // для случая в 50 - если между 25 и 50 (больше 25)
            oper_p(&(*stack_a), &(*stack_b));
        else
            oper_r(&(*stack_b));
        count++;
    }
    if ((max->num - min->num) < 50)
        push_all_stack(stack_b, stack_a);
    else
        sort_b_push_to_a(stack_b, stack_a);
}
