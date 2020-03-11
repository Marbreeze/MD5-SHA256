/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:20:36 by mstratu           #+#    #+#             */
/*   Updated: 2019/10/22 18:41:48 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include "./ft_ssl.h"

# define CH(x, y, z)  ((x & (y ^ z)) ^ z)
# define MAJ(x, y, z) ((x & (y | z)) | (y & z))

# define SIG0(x) (R_ROTATE(x,  7, 32) ^ R_ROTATE(x, 18, 32) ^ R_SHIFT(x,  3))
# define SIG1(x) (R_ROTATE(x, 17, 32) ^ R_ROTATE(x, 19, 32) ^ R_SHIFT(x, 10))
# define S0(x) (R_ROTATE(x, 2, 32) ^ R_ROTATE(x, 13, 32) ^ R_ROTATE(x, 22, 32))
# define S1(x) (R_ROTATE(x, 6, 32) ^ R_ROTATE(x, 11, 32) ^ R_ROTATE(x, 25, 32))

# define SHA256_A 0x6a09e667
# define SHA256_B 0xbb67ae85
# define SHA256_C 0x3c6ef372
# define SHA256_D 0xa54ff53a
# define SHA256_E 0x510e527f
# define SHA256_F 0x9b05688c
# define SHA256_G 0x1f83d9ab
# define SHA256_H 0x5be0cd19

typedef struct			s_bash
{
	uint32_t			val[8];
}						t_bash;

static const uint32_t	g_k[64] =
{
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void					sha256(t_save_str *arg);
t_bash					*sha256_initial(void);
void					sha256_update(t_bash *hash, t_bash *save);
void					sha256_set(uint32_t *str, uint32_t *arr);
void					compress_sha256(t_bash *hash, uint32_t *str);

#endif
