# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bberkass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 22:46:34 by bberkass          #+#    #+#              #
#    Updated: 2021/12/13 22:51:00 by bberkass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

all			:
			$(CC) $(CFLAGS) src/client.c src/ft_putstr.c src/ft_atoi.c -o client
			$(CC) $(CFLAGS) src/server.c src/ft_putstr.c src/ft_putnbr.c -o server

libft		:
			make libft
			rm -f libft.a
			mv ./libft/libft.a .


$(NAME)		: all

clean		:
			rm -f ./client
			rm -f ./server

fclean		: clean


re			: fclean all

.PHONY		:
			libft
