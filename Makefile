# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bberkass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 22:46:34 by bberkass          #+#    #+#              #
#    Updated: 2021/12/13 23:03:06 by bberkass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

all			:
			$(CC) $(CFLAGS) src/client.c src/ft_putstr.c src/ft_atoi.c -o client
			$(CC) $(CFLAGS) src/server.c src/ft_putstr.c src/ft_putnbr.c -o server


$(NAME)		: all

clean		:
			rm -f ./client
			rm -f ./server

fclean		: clean


re			: fclean all

.PHONY		:
			libft
