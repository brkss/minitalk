/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:54:42 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/11 21:35:57 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct ch_s {
	int c;
	int shft;
} ch_t;


void	ft_putstr(char *s);

#endif
