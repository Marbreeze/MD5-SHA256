/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:12:11 by mstratu           #+#    #+#             */
/*   Updated: 2019/02/26 17:49:31 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*csrc;
	char	*cdst;
	size_t	i;

	csrc = (char *)src;
	cdst = (char *)dst;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (cdst);
}
