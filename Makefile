# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bberkass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 22:46:34 by bberkass          #+#    #+#              #
#    Updated: 2021/12/12 18:58:55 by bberkass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror


all			:
			$(CC) $(CFLAGS) client.c -o client
			$(CC) $(CFLAGS) server.c -o server

$(NAME)		: all

clean		:
			rm -f ./client
			rm -f ./server

fclean		: clean


re			: fclean all
