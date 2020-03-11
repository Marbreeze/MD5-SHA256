/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:36:41 by mstratu           #+#    #+#             */
/*   Updated: 2019/10/22 18:52:53 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sha256.h"

t_bash		*sha256_initial(void)
{
	t_bash	*res;

	if (!(res = (t_bash*)malloc(sizeof(t_bash))))
		err_mem();
	res->val[0] = SHA256_A;
	res->val[1] = SHA256_B;
	res->val[2] = SHA256_C;
	res->val[3] = SHA256_D;
	res->val[4] = SHA256_E;
	res->val[5] = SHA256_F;
	res->val[6] = SHA256_G;
	res->val[7] = SHA256_H;
	return (res);
}

void		sha256_update(t_bash *hash, t_bash *save)
{
	int i;

	i = 0;
	while (i < 8)
	{
		hash->val[i] += save->val[i];
		i++;
	}
	i = 0;
	while (i < 8)
	{
		save->val[i] = hash->val[i];
		i++;
	}
}

void		sha256_set(uint32_t *str, uint32_t *arr)
{
	int i;

	i = 0;
	while (i < 16)
	{
		arr[i] = ft_swap_endian32(str[i]);
		i++;
	}
	while (i < 64)
	{
		arr[i] = arr[i - 16] + SIG0(arr[i - 15]) + arr[i - 7] + \
				SIG1(arr[i - 2]);
		i++;
	}
}

void		compress_sha256(t_bash *hash, uint32_t *str)
{
	uint32_t			arr[64];
	uint32_t			temp1;
	uint32_t			temp2;
	int					i;

	i = 0;
	sha256_set(str, arr);
	while (i < 64)
	{
		temp1 = hash->val[7] + arr[i] + g_k[i] + S1(hash->val[4]) + \
				CH(hash->val[4], hash->val[5], hash->val[6]);
		temp2 = S0(hash->val[0]) + MAJ(hash->val[0], hash->val[1], \
				hash->val[2]);
		hash->val[7] = hash->val[6];
		hash->val[6] = hash->val[5];
		hash->val[5] = hash->val[4];
		hash->val[4] = hash->val[3] + temp1;
		hash->val[3] = hash->val[2];
		hash->val[2] = hash->val[1];
		hash->val[1] = hash->val[0];
		hash->val[0] = temp1 + temp2;
		i++;
	}
}

void		sha256(t_save_str *arg)
{
	t_bash		*hash;
	t_bash		*save;
	uint64_t	nr;
	int			i;

	hash = sha256_initial();
	save = sha256_initial();
	nr = 0;
	i = 0;
	while (nr < arg->l)
	{
		compress_sha256(hash, (uint32_t*)(arg->str + nr));
		sha256_update(hash, save);
		nr += 64;
	}
	while (i < 8)
	{
		hash->val[i] = ft_swap_endian32(hash->val[i]);
		i++;
	}
	print_buff_hash(hash->val, 32);
	free(save);
	free(hash);
}
