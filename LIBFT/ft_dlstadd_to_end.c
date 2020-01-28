/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_to_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:00:20 by mburnett          #+#    #+#             */
/*   Updated: 2020/01/27 20:06:29 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstadd_to_end(t_dlist **alst, t_dlist **new)
{
	t_dlist *k;

	k = *alst;
	while (k->next != NULL)
		k = k->next;
    (*new)->previous = k;
    (*new)->next = NULL;
	k->next = *new;
}
