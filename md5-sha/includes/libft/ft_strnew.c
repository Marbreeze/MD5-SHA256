/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:59:04 by mstratu           #+#    #+#             */
/*   Updated: 2019/02/28 15:32:54 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*fresh;

	i = 0;
	fresh = ((char *)malloc(sizeof(char) * (size + 1)));
	if (!fresh)
		return (NULL);
	while (i <= size)
	{
		fresh[i] = '\0';
		i++;
	}
	return (fresh);
}
