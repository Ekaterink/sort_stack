/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:23:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/01/27 19:54:54 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist	*ft_dlstnew(int num)
{
	t_dlist *list;

	if (!(list = (t_dlist *)malloc(sizeof(*list))))
		return (NULL);
	list->num = num;
	list->next = NULL;
	list->previous = NULL;
	return (list);
}
