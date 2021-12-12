/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:53:23 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/12 20:11:50 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

ch_t *g_si;

void	handl(int s)
{
	char	t;

	if (s == SIGUSR1)
	{
		g_si->c = g_si->c | 0;
	}
	else if (s == SIGUSR2)
	{
		g_si->c = g_si->c | 1;
	}
	else {
		write(1, "unkown signal ! \n", 18);
	}
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

void	init_si()
{
	g_si = (ch_t *)malloc(sizeof(ch_t));
	g_si->c = 0b00000000;
	g_si->shft = 0;
}

void    get_pid(int sig, siginfo_t *info, void *context)
{
    (void)context;
	(void)sig;
	printf("sender pid => %d \n", info->si_pid);
	//signalPid = info->si_pid;
}

int main()
{
	pid_t pid;
	struct sigaction        sa;

	init_si();
	signal(SIGUSR1, handl);
	signal(SIGUSR2, handl);
	
	sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = get_pid;
    sigaction(SIGUSR1, &sa, NULL);

	pid = getpid();
	printf("PID => %d \n", pid);
	while (1)
		sleep(1);

	return (0);
}
