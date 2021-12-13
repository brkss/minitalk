/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:53:23 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/13 22:56:55 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_ch	*g_si;

void	handl(int s)
{
	char	t;

	if (s == SIGUSR1)
		g_si->c = g_si->c | 0;
	else if (s == SIGUSR2)
		g_si->c = g_si->c | 1;
	else
		write(1, "unkown signal ! \n", 18);
	if (g_si->shft < 7)
		g_si->c = g_si->c << 1;
	g_si->shft++;
	if (g_si->shft == 8)
	{
		t = (char)(g_si->c);
		write(1, &t, 1);
		g_si->c = 0b00000000;
		g_si->shft = 0;
	}
}

void	init_si(void)
{
	g_si = (t_ch *)malloc(sizeof(t_ch));
	g_si->c = 0b00000000;
	g_si->shft = 0;
}

int	main(void)
{
	pid_t				pid;

	init_si();
	signal(SIGUSR1, handl);
	signal(SIGUSR2, handl);
	pid = getpid();
	ft_putstr("PID => ");
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		sleep(1);
	return (0);
}
