/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:08:49 by mstratu           #+#    #+#             */
/*   Updated: 2019/10/22 19:44:30 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int					turn_flag(char *s)
{
	if (s[1] == 'p')
		return (F_P);
	else if (s[1] == 'q')
		return (F_Q);
	else if (s[1] == 'r')
		return (F_R);
	else if (s[1] == 's')
		return (F_S);
	return (0);
}

char				*ft_str_lenjoiner(const char *s,
					const char *t, size_t c, size_t d)
{
	char			*res;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	if (!(res = (char*)malloc(c + d)))
		return (NULL);
	while (i < c)
		res[j++] = s[i++];
	i = 0;
	while (i < d)
		res[j++] = t[i++];
	return (res);
}

void				err_command(char *av)
{
	ft_putstr("ft_ssl:");
	ft_putstr(av);
	ft_putstr("is an invalid command.\n\n");
	ft_putstr("Message Digest commands:\nmd5\nsha256\n\n");
	exit(EXIT_FAILURE);
}

int					main(int ac, char **av)
{
	int				index;
	t_save_str		*arg;

	index = 0;
	arg = initialize_ssl();
	if (ac < 2)
		ft_putstr_fd("use: ft_ssl command [command opts] [command args]\n", 2);
	else
	{
		index = 2;
		if ((int)(arg->mode = get_algo(av[1])) < 0)
			err_command(av[1]);
		while (index < ac && av[index][0] == '-')
			arg->flags |= turn_flag(av[index++]);
		if (ac == 2 || arg->flags & F_P)
			read_stdin(arg);
		if (arg->flags & F_S)
			hash_str(arg, av, &index);
		while (index < ac)
			hash_file(arg, av[index++], av[1]);
	}
	free(arg);
}
