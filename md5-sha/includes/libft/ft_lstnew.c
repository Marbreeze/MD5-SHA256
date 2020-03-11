/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 23:49:24 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/06 17:00:53 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = (t_list *)malloc(sizeof(t_list));
	if (!fresh)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		fresh->content = ft_memalloc(content_size);
		fresh->content = ft_memcpy(fresh->content, content, content_size);
		fresh->content_size = content_size;
	}
	fresh->next = NULL;
	return (fresh);
}
