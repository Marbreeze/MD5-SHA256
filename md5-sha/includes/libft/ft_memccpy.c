/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:18:01 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/05 20:47:03 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char		*s;
	char			*d;

	s = src;
	d = dst;
	while (n-- > 0)
		if ((*d++ = *s++) == (char)c)
			return (d);
	return (NULL);
}
