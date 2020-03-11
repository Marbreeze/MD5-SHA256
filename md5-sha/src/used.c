/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   used.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:49:20 by mstratu           #+#    #+#             */
/*   Updated: 2019/10/22 19:48:09 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int					read_fd(const int fd, char *buffer)
{
	int				num;

	num = read(fd, buffer, BUFF_SIZE);
	if (num > 0)
		return (num);
	else if (num == 0)
		return (0);
	else
		return (-1);
}

unsigned char		*ft_fdstr(int fd, uint64_t *len)
{
	unsigned char	buffer[BUFF_SIZE + 1];
	unsigned char	*temp;
	unsigned char	*res;
	int				j;

	temp = NULL;
	if (!(res = (unsigned char*)malloc(sizeof(unsigned char))))
		return (NULL);
	*len = 0;
	while ((j = read_fd(fd, (char*)buffer)) > 0)
	{
		buffer[j] = '\0';
		temp = res;
		res = (unsigned char*)ft_str_lenjoiner((char*)temp,\
				(char*)buffer, *len, j);
		free(temp);
		*len += j;
	}
	return (res);
}

unsigned char		*ft_fd_len_str(int fd, uint64_t num, uint64_t *len)
{
	unsigned char	*buffer;

	buffer = (unsigned char*)malloc(sizeof(unsigned char) * num);
	*len = read(fd, buffer, num);
	return (buffer);
}

t_alg				get_algo(char *str)
{
	if (!ft_strcmp("md5", str))
		return (MD5);
	else if (!ft_strcmp("sha256", str))
		return (SHA256);
	return (-1);
}

uint64_t			valid_file(char *file_nm)
{
	struct stat		stat;

	if (!(lstat(file_nm, &stat) == 0))
		err_lstat();
	if ((S_ISDIR(stat.st_mode)))
		return (0);
	else
		return ((uint64_t)stat.st_size);
}
