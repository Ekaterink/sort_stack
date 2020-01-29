//
// Created by Mandi Burnette on 29/01/2020.
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

int checker_valid_command(char *str)
{
    if (ft_strcmp("sa", str) == 0 || ft_strcmp("sb", str) == 0 || ft_strcmp("ss", str) == 0 ||
        ft_strcmp("pa", str) == 0 || ft_strcmp("pb", str) == 0 || ft_strcmp("ra", str) == 0 ||
        ft_strcmp("rb", str) == 0 || ft_strcmp("rr", str) == 0 || ft_strcmp("rra", str) == 0 ||
        ft_strcmp("rrb", str) == 0 || ft_strcmp("rrr", str) == 0)
        return (1);
    return (0);
}

//////////////////////  КОНЕЦ ВАЛИДАЦИИ  ////////////////////////