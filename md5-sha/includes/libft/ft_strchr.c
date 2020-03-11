/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:24:16 by mstratu           #+#    #+#             */
/*   Updated: 2019/02/28 18:09:32 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
