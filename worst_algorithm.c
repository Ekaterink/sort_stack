//
// Created by Mandi Burnette on 31/01/2020.
//

#include "LIBFT/libft.h"
#include "LIBFT/dlist.h"


t_dlist *get_stack_arr()
{
    t_dlist *new;
    t_dlist *begin;
    int k;

    int a[11] = {1,5,2,7,9,4,0,8,6,3};

//    int a[11] = {9,8,7,6,5,4,3,2,1,0};
    // first element of list
    begin = ft_dlstnew(a[0]);

    //other elements
    k = 1;
    while (k < 10)
    {
        new = ft_dlstnew(a[k]);
        ft_dlstadd_to_end(&begin, &new);
        k++;
    }
    return (begin);
}

t_dlist     *find_min(t_dlist *begin)
{
    t_dlist *min;

    min = begin;
    while (begin)
    {
        if (begin->num < min->num)
            min = begin;
        begin = begin->next;
    }
    return (min);
}

t_dlist     *find_max(t_dlist *begin)
{
    t_dlist *max;

    max = begin;
    while (begin)
    {
        if (begin->num > max->num)
            max = begin;
        begin = begin->next;
    }
    return (max);
}

int     find_number(t_dlist *begin, t_dlist *list)
{
    int i;

    i = 1;
    while (list->num != begin->num)
    {
        begin = begin->next;
        i++;
    }
    return (i);
}

int     ft_dlistlen(t_dlist *begin)
{
    int i;

    i = 0;
    if (begin)
    {
        i++;
        while (begin->next != NULL)
        {
            begin = begin->next;
            i++;
        }
    }
    return (i);
}
/*
int main(void)
{
    t_dlist *stack_a;
    t_dlist *stack_b;
    t_dlist *begin;
    t_dlist *min;
    int num;
    int all_num;
    int iter;

    stack_a = get_stack_arr();
    begin = stack_a;
    iter = 0;


    while (stack_a != NULL) // перекидываем все в стек Б от наименьшего к наибольшему
    {
        min = find_min(stack_a);
        num = find_number(stack_a, min);
        all_num = ft_dlistlen(stack_a);

        if (num == 1) // если в топе
            oper_p(&stack_b, &stack_a);
        else if (num < all_num / 2 + 1) // если в верней части стека
            oper_r(&stack_a);
        else // в нижней части стека
            oper_rr(&stack_a);
        iter++;
    }
    while (stack_b != NULL) // перекидываем обратно в А
    {
        oper_p(&stack_a, &stack_b);
        iter++;
    }


    printf("%s", "\nstack_A: ");
    while (stack_a) // check of stack_a
    {
        printf("%d", stack_a->num);
        stack_a = stack_a->next;
    }
    printf("%s", "\nstack_B: ");
    while (stack_b) // check of stack_b
    {
        printf("%d", stack_b->num);
        stack_b = stack_b->next;
    }
    printf("iterations = %d", iter);
return 0;
}*/