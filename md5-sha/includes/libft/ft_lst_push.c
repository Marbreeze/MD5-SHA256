/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:22:53 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/05 13:31:32 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lst_push(t_list *list, t_list *node)
{
	if (node == NULL)
		return ;
	if (list == NULL)
	{
		list = node;
		return ;
	}
	while (list->next)
	{
		list = list->next;
	}
	list->next = node;
}
