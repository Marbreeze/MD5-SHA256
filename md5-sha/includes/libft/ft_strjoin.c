/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:02:34 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/05 11:59:02 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		g;
	int		i;
	char	*fresh;

	g = 0;
	i = 0;
	if (!s1 || !s2 || !(fresh = (char*)malloc(sizeof(char) * \
	ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i])
	{
		fresh[i] = s1[i];
		i++;
	}
	while (s2[g])
	{
		fresh[i] = s2[g];
		i++;
		g++;
	}
	fresh[i] = '\0';
	return (fresh);
}
