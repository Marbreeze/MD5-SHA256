/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeerr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:15:58 by mstratu           #+#    #+#             */
/*   Updated: 2019/10/22 19:23:41 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void		print(char *str, char *mode)
{
	write(1, mode, ft_strlen(mode));
	ft_putstr(" (");
	write(1, str, ft_strlen(str));
	ft_putstr(") = ");
}

void		err_lstat(void)
{
	write(1, "ft_ssl: Error: Error reading from file (lstat return -1)", 57);
	exit(EXIT_FAILURE);
}
