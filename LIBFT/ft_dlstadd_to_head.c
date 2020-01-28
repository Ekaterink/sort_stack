/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_to_head.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:55:56 by mburnett          #+#    #+#             */
/*   Updated: 2020/01/27 20:00:06 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstadd_to_head(t_dlist **alst, t_dlist *new)
{
	new->previous = NULL;
	new->next = (*alst);
    (*alst)->previous = new;
    (*alst) = new;
}
