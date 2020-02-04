//
// Created by Mandi Burnette on 28/01/2020.
//
#include "LIBFT/libft.h"
#include "LIBFT/dlist.h"

void    solve_command(t_dlist **stack_a, t_dlist **stack_b, char *str)
{
    if (ft_strcmp("sa", str) == 0)
        oper_s(stack_a);
    else if (ft_strcmp("sb", str) == 0)
        oper_s(stack_b);
    else if (ft_strcmp("ss", str) == 0)
    {
        oper_s(stack_a);
        oper_s(stack_b);
    }
    else if (ft_strcmp("pa", str) == 0)
        oper_p(stack_a, stack_b);
    else if (ft_strcmp("pb", str) == 0)
        oper_p(stack_b, stack_a);
    else if (ft_strcmp("ra", str) == 0)
        oper_r(stack_a);
    else if (ft_strcmp("rb", str) == 0)
        oper_r(stack_b);
    else if (ft_strcmp("rr", str) == 0)
    {
        oper_r(stack_a);
        oper_r(stack_b);
    }
    else if (ft_strcmp("rra", str) == 0)
        oper_rr(stack_a);
    else if (ft_strcmp("rrb", str) == 0)
        oper_rr(stack_b);
    else if (ft_strcmp("rrr", str) == 0)
    {
        oper_rr(stack_a);
        oper_rr(stack_b);
    }
}

t_dlist *get_stack_a(char **av)
{
    t_dlist *new;
    t_dlist *begin;
    int i;

    // first element of list
    i = 2;
    begin = ft_dlstnew(ft_atoi(av[1]));

    //other elements
    while (av[i])
    {
        new = ft_dlstnew(ft_atoi(av[i]));
        ft_dlstadd_to_end(&begin, &new);
        i++;
    }
    return (begin);
}

void    do_operations(t_dlist **stack_a, t_dlist **stack_b, char **str)
{
    int i;

    i = 0;
    while (str[i] && checker_valid_command(str[i]))
    {
        solve_command(stack_a, stack_b, str[i]);
        i++;
    }
}

int     list_len(t_dlist *stack)
{
    t_dlist *list;
    int count;

    count = 0;
    list = stack;
    while (list)
    {
        count++;
        list = list->next;
    }
    return (count);
}

void    checker_OK(t_dlist **stack_a, t_dlist **stack_b)
{
    int num;
    int prev;
    int flag;
    t_dlist *a;

    a = (*stack_a);
    flag = 0;
    if ((*stack_b) == NULL)
    {
        prev = a->num;
        while (a->next)
        {
            a = a->next;
            num = a->num;
            if (num < prev)
            {
                printf("%s", "KO\n");
                flag = 1;
                break;
            }
            else
            {
                prev = a->num;
            }
        }
        if (flag == 0)
            printf("%s", "OК\n");
    }
    else
        printf("%s", "KO\n");
}

////////////////////////////////      main       //////////////////////

/*

int main(int ac, char **av)
{
    int i;
    char *str[100];
    t_dlist *stack_a;
    t_dlist *stack_b;
    int proverka;

    proverka = 1;
    i = 0;
    if (ac == 1)
        return 0;
    else
    {
        if (checker_valid_isdigit(av) == 0) // валидация аргументов
            return 0;
        stack_a = get_stack_a(av); // записываем аргументы в стэк А
        while (get_next_line(0, &(str[i])) > 0) // если она - одна из команд
        {
            if ((proverka = checker_valid_command(str[i])) == 0) // если проверка провалилась
            {
                printf("%s", "Error\nAn instruction don’t exist and/or is incorrectly formatted\n");
                break;
            }
            i++;
        }
        if (proverka == 1) {
            do_operations(&stack_a, &stack_b, str);
            checker_OK(&stack_a, &stack_b);


//                 i = 0;
//                 while (str[i]) // check of str
//                 {
//                     printf("%s", str[i]);
//                     i++;
//                 }

            printf("%s", "stack_A: ");
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
            return 0;
        }
    }

    return 0;
}
*/