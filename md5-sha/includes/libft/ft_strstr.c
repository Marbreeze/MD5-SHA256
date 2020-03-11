/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:34:38 by mstratu           #+#    #+#             */
/*   Updated: 2019/02/28 18:18:00 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		g;
	int		r;

	i = 0;
	g = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		g = 0;
		if (haystack[i] == needle[g])
		{
			r = i;
			while (haystack[r] == needle[g])
			{
				if (needle[g + 1] == '\0')
					return (&((char *)haystack)[i]);
				g++;
				r++;
			}
		}
		i++;
	}
	return (0);
}
