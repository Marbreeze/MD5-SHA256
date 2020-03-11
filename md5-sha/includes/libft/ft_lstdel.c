/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:33:01 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/06 19:53:15 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*temp;
	t_list		*temp_next;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	temp = *alst;
	temp_next = temp->next;
	while (temp_next)
	{
		del(temp->content, temp->content_size);
		temp_next = temp->next;
		free(temp);
		temp = temp_next;
	}
	*alst = NULL;
}
