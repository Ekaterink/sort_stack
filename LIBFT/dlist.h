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

#endif
