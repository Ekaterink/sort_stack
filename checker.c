//
// Created by Mandi Burnette on 28/01/2020.
//
#include "LIBFT/libft.h"
#include "LIBFT/dlist.h"

//////////////////////  ВАЛИДАЦИЯ  ////////////////////////

int checker_valid_duplicates(char **av)
{
    int i;
    int count;
    int j;
    int num;

    i = 1;
    while (av[i])
    {
        num = ft_atoi(av[i]);
        j = 1;
        count = 0;
        while (av[j])
        {
            if (ft_atoi(av[j]) == num)
                count++;
            j++;
        }
        if (count > 1)
        {
            printf("%s", "Error\n");
            printf("%s", "Duplicate\n");
            return (0);
        }
        i++;
    }
    return (1);
}

int checker_valid_overflow(char **av)
{
    int i;
    int num;

    i = 1;
    while (av[i])
    {
        num = ft_atoi(av[i]);
        if ((num == 0 || num == -1) && ft_strlen(av[i]) > 2)
        {
            printf("%s", "Error\n");
            printf("%s", "Integer overflow\n");
            return (0);
        }
        i++;
    }
    return (checker_valid_duplicates(av));
}

int checker_valid_isdigit(char **av)
{
    int i;
    int j;

    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
          //  printf("digit is %d\n", (av[i][j] - '0'));
            if (isdigit(av[i][j]) == 0 && av[i][j] != '-' && av[i][j] != '+') // if not a number
            {
                printf("%s", "Error\n");
                printf("%s", "Not a digit\n");
                return 0;
            }
            j++;
        }
        i++;
    }
    return (checker_valid_overflow(av));
}

char *checker_valid_command(char *str)
{
    if (ft_strcmp("sa", str) == 0 || ft_strcmp("sb", str) == 0 || ft_strcmp("ss", str) == 0 ||
            ft_strcmp("pa", str) == 0 || ft_strcmp("pb", str) == 0 || ft_strcmp("ra", str) == 0 ||
            ft_strcmp("rb", str) == 0 || ft_strcmp("rr", str) == 0 || ft_strcmp("rra", str) == 0 ||
            ft_strcmp("rrb", str) == 0 || ft_strcmp("rrr", str) == 0)
        return (str);
    return (0);
}

//////////////////////  КОНЕЦ ВАЛИДАЦИИ  ////////////////////////

void    oper_sa(t_dlist **stack_a, t_dlist **stack_b)
{
    t_dlist *begin_a;
    t_dlist *second_el;
    int count = 0;

    begin_a = *stack_a;
    while (begin_a)
    {
        count++;
        begin_a = begin_a->next;
    }
    if (count < 2)
        ;
    else
    {
        begin_a = *stack_a;
        second_el = begin_a->next;
        begin_a->next = second_el->next;
        begin_a->previous = second_el;
        second_el->next = begin_a;
        second_el->previous = NULL;
        begin_a = second_el;
    }

}

void    *solve_command(t_dlist **stack_a, t_dlist **stack_b, char *str)
{
    if (ft_strcmp("sa", str) == 0)
        oper_sa(stack_a, stack_b);
    else if (ft_strcmp("sb", str) == 0)
        ;
    else if (ft_strcmp("ss", str) == 0)
        ;
    else if (ft_strcmp("pa", str) == 0)
        ;
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
//    char *oper;

    i = 0;
    while (str[i] && checker_valid_command(str[i]))
    {
        solve_command(stack_a, stack_b, str[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    int i;
    char *str[33];
    t_dlist *stack_a;
    t_dlist *stack_b;

    i = 0;
    if (ac == 1)
        return 0;
    else
    {
        if (checker_valid_isdigit(av) == 0) // валидация аргументов
            return 0;
        stack_a = get_stack_a(av); // записываем аргументы в стэк А
        get_next_line(0, &(str[i])); // считываем первую строку
        while (checker_valid_command(str[i])) // если она - одна из команд
        {
            i++;
            get_next_line(0, &(str[i]));
        }

        do_operations(&stack_a, &stack_b, str);









   /*     i = 0;
        while (str[i]) // check of ss sb
        {
            printf("%s", str[i]);
            i++;
        }
*/

        while (stack_a) // check of stack_a
        {
            printf("%d", stack_a->num);
            stack_a = stack_a->next;
        }

    }

    return 0;
}