/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:48:50 by mstratu           #+#    #+#             */
/*   Updated: 2019/03/06 19:48:06 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void				ft_putnbr(int n)
{
	unsigned int	num;
	char			c;

	if (n < 0)
	{
		write(1, "-", 1);
		num = (-1) * n;
	}
	else
		num = n;
	if (num > 9)
		ft_putnbr(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}
