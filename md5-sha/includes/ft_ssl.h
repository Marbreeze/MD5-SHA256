/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:50:54 by mstratu           #+#    #+#             */
/*   Updated: 2019/10/22 18:41:15 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>

# define F_P		1
# define F_Q		2
# define F_R		4
# define F_S		8

# define L_ROTATE(x, n, b) (x << n | (x >> (b - n)))
# define R_ROTATE(x, n, b) ((x >> n) | (x << (b - n)))
# define L_SHIFT(x, n) (x << n)
# define R_SHIFT(x, n) (x >> n)

typedef struct		s_buff_hash
{
	uint32_t		val[4];
	uint32_t		f;
}					t_buff_hash;

typedef enum		e_alg
{
	MD5,
	SHA256
}					t_alg;

typedef struct		s_save_str
{
	t_alg			mode;
	int				flags;
	unsigned char	*str;
	uint64_t		len;
	uint64_t		l;
}					t_save_str;

typedef void		(*t_mode)(t_save_str *args);

void				encode(unsigned char *res, uint32_t *hash, unsigned int \
					len);
void				err_command(char *str);
void				err_mem(void);
void				err_input(void);
void				err_lstat(void);
unsigned char		*ft_fdstr(int fd, uint64_t *len);
unsigned char		*ft_fd_len_str(int fd, uint64_t num, uint64_t *len);
char				*ft_str_lenjoiner(const char *s, const char *t, size_t c, \
					size_t	d);
uint64_t			ft_swap_endian64(uint64_t num);
uint32_t			ft_swap_endian32(uint32_t num);
t_alg				get_algo(char *s);
int					turn_flag(char *s);
void				hash_str(t_save_str *args, char **av, int *i);
void				hash_file(t_save_str *args, char *str_name, char *mode);
t_save_str			*initialize_ssl(void);
void				pad(t_save_str *arg, unsigned char *input);
void				print_buff_hash(uint32_t *hash, uint8_t len);
void				read_stdin(t_save_str *args);
uint64_t			valid_file(char *file_nm);

void				conversion(unsigned char *res, uint8_t len);
int					hex_len(unsigned long num);
void				print_hex(unsigned long num);
void				md5(t_save_str *arg);
void				sha256(t_save_str *arg);
void				print(char *str, char *mode);

#endif
