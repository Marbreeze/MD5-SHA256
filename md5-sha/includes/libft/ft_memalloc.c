/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:51:04 by mstratu           #+#    #+#             */
/*   Updated: 2019/02/25 19:53:27 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*fresh;

	fresh = malloc(size);
	if (!fresh)
		return (NULL);
	ft_bzero(fresh, size);
	return (fresh);
}
