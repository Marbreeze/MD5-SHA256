/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:22:57 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/05 21:26:47 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	get_len(int x)
{
	int		c;

	if (x == 0)
		return (1);
	c = 0;
	if (x < 0)
		c = 1;
	while (x)
	{
		c++;
		x /= 10;
	}
	return (c);
}

char		*ft_itoa(int n)
{
	char			*fresh;
	unsigned int	num;
	int				j;

	j = get_len(n);
	fresh = (char *)malloc(sizeof(char) * (j + 1));
	if (!fresh)
		return (NULL);
	fresh[j] = '\0';
	j--;
	fresh[j] = '0';
	if (n < 0)
	{
		fresh[0] = '-';
		num = n * (-1);
	}
	else
		num = n;
	while (num)
	{
		fresh[j] = ((num % 10) + '0');
		num /= 10;
		j--;
	}
	return (fresh);
}
