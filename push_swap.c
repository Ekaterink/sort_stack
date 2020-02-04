//
// Created by Mandi Burnette on 03/02/2020.
//

#include "LIBFT/libft.h"
#include "LIBFT/dlist.h"

void    sort_b(t_dlist **stack_b)
{

}

void    sort_a(t_dlist **stack_a, t_dlist **stack_b)
{
    t_dlist *min;

    min = find_min((*stack_b));
//    while ((*stack_a) && (*stack_a)->next && ((*stack_a)->num > (*stack_a)->next->num))
//    {
//        oper_r(&(*stack_a));
//    }



    while ((*stack_a) && (*stack_a)->next) //((*stack_a) && (*stack_a)->num != min->num)
    {
        if ((*stack_a)->num > (*stack_a)->next->num)
            oper_p(&(*stack_b), &(*stack_a));
        else
        {
            oper_r(&(*stack_a));
            break;
        }
    }

//    sort_b(stack_a, stack_b);
}

void sort_hundred(t_dlist **list)
{
    t_dlist *stack_a;
    t_dlist *stack_b;

    stack_a = (*list);
    stack_b = NULL;

    first_sort(&stack_a, &stack_b);
    second_sort(&stack_a, &stack_b);
    sort_a(&stack_a, &stack_b);

    printf("%s", "stack_A: ");
    while (stack_a) // check of stack_a
    {
        printf("%d ", stack_a->num);
        stack_a = stack_a->next;
    }

    printf("%s", "\nstack_B: ");
    while (stack_b) // check of stack_b
    {
        printf("%d ", stack_b->num);
        stack_b = stack_b->next;
    }

}

int main(int ac, char **av)
{
    int i;
    char *str[100];
    t_dlist *stack_a;
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
        if (ac < 101)
            sort_hundred(&stack_a);
//        else
//            sort_bigdata();
    }

    return 0;
}