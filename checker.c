//
// Created by Mandi Burnette on 28/01/2020.
//
#include "LIBFT/libft.h"
#include "LIBFT/dlist.h"

int checker_valid_duplicates(char **av)
{
    int i;
    int num;
    t_dlist *begin;
    t_dlist *new;
    t_dlist *tmp;

    i = 2;
    begin = ft_dlstnew(ft_atoi(av[1]));
    while (av[i])
    {
        num = ft_atoi(av[i]);
        new = ft_dlstnew(num);
        ft_dlstadd_to_end(&begin, &new);
        i++;
    }
    tmp = begin;
    while(*tmp)
    {
        num = tmp->num;
        while ()

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
    return (1);
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

int main(int ac, char **av)
{
    if (ac == 1)
        return 0;
    else
    {
        if (checker_valid_isdigit(av) == 0)
        {
          //  printf("%s", "not passing validation");
            return 0;
        }

    }
    return 0;
}