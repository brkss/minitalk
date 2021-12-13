/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:54:42 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/13 01:50:00 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct ch_s {
	int	c;
	int	shft;
}	t_ch;

void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		ft_atoi(const char *s);

#endif
