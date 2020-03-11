# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 23:27:12 by mstratu           #+#    #+#              #
#    Updated: 2019/08/07 16:22:51 by mstratu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS = ft_itoa.c ft_memcmp.c ft_putstr.c ft_striteri.c ft_strnew.c \
ft_lst_push.c ft_memcpy.c ft_putstr_fd.c ft_strjoin.c ft_strnstr.c \
ft_atoi.c ft_lstadd.c ft_memdel.c ft_strcat.c ft_strlcat.c ft_strrchr.c \
ft_bzero.c ft_lstdel.c ft_memmove.c ft_strchr.c ft_strlen.c ft_strsplit.c \
ft_isalnum.c ft_lstdelone.c ft_memset.c ft_strclr.c ft_strlower.c ft_strstr.c \
ft_isalpha.c ft_lstiter.c ft_putchar.c ft_strcmp.c ft_strmap.c ft_strsub.c \
ft_isascii.c ft_lstmap.c ft_putchar_fd.c ft_strcpy.c ft_strmapi.c ft_strtrim.c \
ft_isdigit.c ft_lstnew.c ft_putendl.c ft_strdel.c ft_strncat.c ft_strupper.c \
ft_ismax.c ft_memalloc.c ft_putendl_fd.c ft_strdup.c ft_strncmp.c ft_tolower.c \
ft_ismin.c ft_memccpy.c ft_putnbr.c ft_strequ.c ft_strncpy.c ft_toupper.c \
ft_isprint.c ft_memchr.c ft_putnbr_fd.c ft_striter.c ft_strnequ.c ft_iswhtspc.c

OBJ = ft_itoa.o ft_memcmp.o ft_putstr.o ft_striteri.o ft_strnew.o \
ft_lst_push.o ft_memcpy.o ft_putstr_fd.o ft_strjoin.o ft_strnstr.o \
ft_atoi.o ft_lstadd.o ft_memdel.o ft_strcat.o ft_strlcat.o ft_strrchr.o \
ft_bzero.o ft_lstdel.o ft_memmove.o ft_strchr.o ft_strlen.o ft_strsplit.o \
ft_isalnum.o ft_lstdelone.o ft_memset.o ft_strclr.o ft_strlower.o ft_strstr.o \
ft_isalpha.o ft_lstiter.o ft_putchar.o ft_strcmp.o ft_strmap.o ft_strsub.o \
ft_isascii.o ft_lstmap.o ft_putchar_fd.o ft_strcpy.o ft_strmapi.o ft_strtrim.o \
ft_isdigit.o ft_lstnew.o ft_putendl.o ft_strdel.o ft_strncat.o ft_strupper.o \
ft_ismax.o ft_memalloc.o ft_putendl_fd.o ft_strdup.o ft_strncmp.o ft_tolower.o \
ft_ismin.o ft_memccpy.o ft_putnbr.o ft_strequ.o ft_strncpy.o ft_toupper.o \
ft_isprint.o ft_memchr.o ft_putnbr_fd.o ft_striter.o ft_strnequ.o ft_iswhtspc.o

INCLUDES=./

$(NAME): $(SRCS) libft.h
	gcc  -Wall -Wextra -Werror -I $(INCLUDES) -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
