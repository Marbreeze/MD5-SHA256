/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:03:28 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/01 16:35:55 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	i = 0;
	if (!s && s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * (len) + 1);
	if (!fresh)
		return (NULL);
	while (i < len && s[start])
	{
		fresh[i] = s[i + start];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
