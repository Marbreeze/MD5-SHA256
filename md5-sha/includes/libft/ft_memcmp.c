/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:16:55 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/06 16:20:33 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*f1;
	const unsigned char	*f2;

	f1 = (unsigned char *)s1;
	f2 = (unsigned char *)s2;
	while (n--)
	{
		if (*f1 != *f2)
			return (*f1 - *f2);
		f1++;
		f2++;
	}
	return (0);
}
