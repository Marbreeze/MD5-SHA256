/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:52:40 by mstratu           #+#    #+#             */
/*   Updated: 2019/10/22 19:54:23 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/md5.h"

t_buff_hash			*md5_initial(void)
{
	t_buff_hash		*res;

	if (!(res = (t_buff_hash*)malloc(sizeof(t_buff_hash))))
		err_mem();
	res->val[0] = MD5_A;
	res->val[1] = MD5_B;
	res->val[2] = MD5_C;
	res->val[3] = MD5_D;
	res->f = 0;
	return (res);
}

void				update_md5(t_buff_hash *hash, t_buff_hash *save)
{
	int				i;

	i = 0;
	while (i < 4)
	{
		hash->val[i] += save->val[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		save->val[i] = hash->val[i];
		i++;
	}
}

void				set_md5(t_buff_hash *hash, uint32_t *str, uint8_t g, int i)
{
	uint64_t		temp;

	temp = hash->val[3];
	hash->val[3] = hash->val[2];
	hash->val[2] = hash->val[1];
	hash->val[1] = hash->val[1] + L_ROTATE((hash->val[0] + hash->f + \
				g_sines[i] + str[g]), g_shift[i], 64);
	hash->val[0] = temp;
}

void				compress_md5(t_buff_hash *hash, uint32_t *str, int i)
{
	uint8_t			g;

	if (i < 16)
	{
		hash->f = F(hash->val[1], hash->val[2], hash->val[3]);
		g = i;
	}
	else if (i < 32)
	{
		hash->f = G(hash->val[1], hash->val[2], hash->val[3]);
		g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		hash->f = H(hash->val[1], hash->val[2], hash->val[3]);
		g = (3 * i + 5) % 16;
	}
	else
	{
		hash->f = I(hash->val[1], hash->val[2], hash->val[3]);
		g = (7 * i) % 16;
	}
	set_md5(hash, str, g, i);
}

void				md5(t_save_str *arg)
{
	t_buff_hash		*hash;
	t_buff_hash		*save;
	uint64_t		nr;
	int				i;

	nr = 0;
	hash = md5_initial();
	save = md5_initial();
	while (nr < arg->l)
	{
		i = 0;
		while (i < 64)
		{
			compress_md5(hash, (uint32_t*)(arg->str + nr), i);
			i++;
		}
		update_md5(hash, save);
		nr += 64;
	}
	print_buff_hash(save->val, 16);
	free(hash);
	free(save);
}
