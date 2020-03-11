/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:41:12 by mstratu           #+#    #+#             */
/*   Updated: 2019/02/28 19:43:49 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fresh;

	i = 0;
	if (!s || !f)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!fresh)
		return (NULL);
	while (s[i])
	{
		fresh[i] = (*f)(i, (s[i]));
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
