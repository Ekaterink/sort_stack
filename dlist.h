#ifndef LIST_H
# define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct	s_dlist
{
	int				num;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}				t_dlist;

t_dlist	*ft_dlstnew(int num);
void	ft_dlstadd_to_end(t_dlist **alst, t_dlist **new);
void	ft_dlstadd_to_head(t_dlist **alst, t_dlist *new);
int     checker_valid_duplicates(char **av);
int     checker_valid_overflow(char **av);
int     checker_valid_isdigit(char **av);
int     checker_valid_command(char *str);
void    oper_s(t_dlist **stack_a);
void    oper_p(t_dlist **stack_push, t_dlist **stack_pop);
void    oper_r(t_dlist **stack);
void    oper_rr(t_dlist **stack);
void    checker_OK(t_dlist **stack_a, t_dlist **stack_b);
void    solve_command(t_dlist **stack_a, t_dlist **stack_b, char *str);
t_dlist *get_stack_a(char **av);
void    do_operations(t_dlist **stack_a, t_dlist **stack_b, char **str);
int     list_len(t_dlist *stack);
void    checker_OK(t_dlist **stack_a, t_dlist **stack_b);
t_dlist     *find_min(t_dlist *begin);
int     ft_dlistlen(t_dlist *begin);
t_dlist     *find_max(t_dlist *begin);
void    push_all_stack(t_dlist **stack_b, t_dlist **stack_a);
void    sort_b_push_to_a(t_dlist **stack_b, t_dlist **stack_a);
void    first_sort(t_dlist **stack_a, t_dlist **stack_b);
void    second_sort(t_dlist **stack_a, t_dlist **stack_b);


#endif
