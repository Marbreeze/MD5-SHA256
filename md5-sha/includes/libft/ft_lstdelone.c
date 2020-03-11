/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:18:42 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/06 16:04:27 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (del != NULL && alst != NULL && (*alst) != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
	}
	free(*alst);
	*alst = NULL;
}
