/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:58:49 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/06 16:02:52 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
}
