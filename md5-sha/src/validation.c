/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:15:33 by mstratu           #+#    #+#             */
/*   Updated: 2019/10/22 19:40:33 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

uint64_t		ft_swap_endian64(uint64_t number)
{
	return ((number << 56) | \
			((number & 0x000000000000FF00) << 40) | \
			((number & 0x0000000000FF0000) << 24) | \
			((number & 0x00000000FF000000) << 8) | \
			((number & 0x000000FF00000000) >> 8) | \
			((number & 0x0000FF0000000000) >> 24) | \
			((number & 0x00FF000000000000) >> 40) | \
			(number >> 56));
}

uint32_t		ft_swap_endian32(uint32_t number)
{
	return (((number >> 24) & 0x000000ff) | ((number >> 8) & 0x0000ff00) | \
			((number << 8) & 0x00ff0000) | ((number << 24) & 0xff000000));
}

void			err_mem(void)
{
	write(1, "ft_ssl: Error: your computer is out of memory space\n", 54);
	exit(EXIT_FAILURE);
}

void			pad(t_save_str *arg, unsigned char *my_input)
{
	int			block_size;

	block_size = 64;
	arg->l = arg->len + 9;
	while (arg->l % block_size != 0)
		arg->l += 1;
	if (!(arg->str = (unsigned char*)malloc(sizeof(unsigned char) * arg->l)))
		err_mem();
	ft_bzero(arg->str, arg->l);
	ft_memcpy(arg->str, my_input, arg->len);
	*(uint64_t*)(arg->str + arg->len) = 0x80;
	*(uint64_t*)(arg->str + (arg->l - 8)) = (arg->mode == MD5) ? \
	(8 * arg->len) : ft_swap_endian64((8 * arg->len));
}

t_save_str		*initialize_ssl(void)
{
	t_save_str	*strct;

	if (!(strct = (t_save_str*)malloc(sizeof(t_save_str))))
		err_mem();
	strct->flags = 0;
	return (strct);
}
