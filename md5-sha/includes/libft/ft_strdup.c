/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:56:17 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/05 17:15:20 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	int			i;
	int			g;
	char		*fresh;

	i = 0;
	g = 0;
	fresh = ((char *)malloc(sizeof(char) * (ft_strlen(s) + 1)));
	if (!fresh)
		return (NULL);
	while (s[i])
	{
		fresh[g] = s[i];
		g++;
		i++;
	}
	fresh[g] = '\0';
	return (fresh);
}
