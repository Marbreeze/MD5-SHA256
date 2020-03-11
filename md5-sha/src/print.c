/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:37:25 by mstratu           #+#    #+#             */
/*   Updated: 2019/10/22 19:42:07 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void				encode(unsigned char *str, uint32_t *hash, unsigned int len)
{
	unsigned int	i;
	unsigned int	pos_of_has;

	i = 0;
	pos_of_has = 0;
	while (i < len)
	{
		str[i] = (unsigned char)(hash[pos_of_has] & 0xff);
		str[i + 1] = (unsigned char)((hash[pos_of_has] >> 8) & 0xff);
		str[i + 2] = (unsigned char)((hash[pos_of_has] >> 16) & 0xff);
		str[i + 3] = (unsigned char)((hash[pos_of_has] >> 24) & 0xff);
		i += 4;
		pos_of_has++;
	}
}

void				conversion(unsigned char *res, uint8_t len)
{
	uint8_t			i;
	int				num;

	i = 0;
	while (i < len)
	{
		num = hex_len((unsigned long)res[i]);
		if (num == 1)
		{
			ft_putchar('0');
			print_hex((unsigned long)res[i]);
		}
		else
			print_hex((unsigned long)res[i]);
		i++;
	}
}

int					hex_len(unsigned long num)
{
	int				res;

	res = 1;
	while (num > 15)
	{
		num /= 16;
		res++;
	}
	return (res);
}

void				print_hex(unsigned long num)
{
	char			*tab;

	tab = "0123456789abcdef";
	if (num > 15)
	{
		print_hex(num / 16);
		print_hex(num % 16);
	}
	else
		ft_putchar(tab[num]);
}

void				print_buff_hash(uint32_t *hash, uint8_t len)
{
	unsigned char	res[len];

	encode(res, hash, len);
	conversion(res, len);
}
