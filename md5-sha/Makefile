# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 23:21:30 by mstratu           #+#    #+#              #
#    Updated: 2019/10/22 02:40:26 by mstratu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
CFLAGS = -Wall -Wextra -Werror
SRCS = src/*.c
OBJS = *.o

all: $(NAME)

$(NAME):
	@make -C ./includes/libft/ fclean
	@make -C ./includes/libft/
	@gcc $(CFLAGS) -I ./includes/libft/ -c $(SRCS)
	@gcc -o $(NAME) $(OBJS) -L ./includes/libft -lft

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
