/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:36:55 by mstratu           #+#    #+#             */
/*   Updated: 2019/10/22 19:22:57 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

t_mode	g_dispatch[2] =
{
	md5,
	sha256
};

void		err_file(void)
{
	write(1, "File is empty not reading from fd", 34);
	exit(EXIT_FAILURE);
}

void		err_my_input(void)
{
	write(1, "ft_ssl: Error: problem reading from STDIN\n", 44);
	exit(EXIT_FAILURE);
}

void		read_stdin(t_save_str *args)
{
	unsigned char	*my_input;

	if (!(my_input = ft_fdstr(0, &args->len)))
		err_my_input();
	if (args->flags & F_P && !(args->flags & F_Q))
		ft_putstr((char*)my_input);
	pad(args, my_input);
	free(my_input);
	g_dispatch[args->mode](args);
	if (args->str)
		free(args->str);
	ft_putchar('\n');
}

void		hash_str(t_save_str *arg, char **av, int *i)
{
	arg->len = ft_strlen(av[*i]);
	pad(arg, (unsigned char*)av[*i]);
	if (!(arg->flags & F_Q) && !(arg->flags & F_R))
	{
		ft_putstr(av[1]);
		ft_putchar(' ');
		ft_putstr(" (\"");
		write(1, av[*i], ft_strlen(av[*i]));
		ft_putstr("\") = ");
	}
	g_dispatch[arg->mode](arg);
	if (arg->str)
		free(arg->str);
	if (!(arg->flags & F_Q) && arg->flags & F_R)
		write(1, av[*i], ft_strlen(av[*i]));
	ft_putchar('\n');
	*i += 1;
}

void		hash_file(t_save_str *arg, char *str_name, char *mode)
{
	unsigned char	*my_input;
	int				fd;

	if ((fd = open(str_name, O_RDONLY)) < 0)
	{
		write(1, "no such file  or flags", 23);
		return ;
	}
	if (!(arg->len = valid_file(str_name)))
		return ;
	if (!(my_input = ft_fd_len_str(fd, arg->len, &arg->len)))
		err_file();
	if (!(arg->flags & F_Q) && !(arg->flags & F_R))
		print(str_name, mode);
	pad(arg, my_input);
	free(my_input);
	g_dispatch[arg->mode](arg);
	if (arg->str)
		free(arg->str);
	if (!(arg->flags & F_Q) && (arg->flags & F_R))
	{
		ft_putchar(' ');
		ft_putstr(str_name);
	}
	ft_putchar('\n');
}
