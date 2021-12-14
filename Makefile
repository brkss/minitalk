# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bberkass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 22:46:34 by bberkass          #+#    #+#              #
#    Updated: 2021/12/14 03:43:12 by bberkass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		= client

SERVER		= server

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

all			: $(CLIENT) $(SERVER)

$(CLIENT)	:
				$(CC) $(CFLAGS) src/client.c src/ft_putstr.c src/ft_atoi.c -o client

$(SERVER)	:
				$(CC) $(CFLAGS) src/server.c src/ft_putstr.c src/ft_putnbr.c -o server

clean		:
			rm -f ./client
			rm -f ./server

fclean		: clean


re			: fclean all

.PHONY		:
			libft
