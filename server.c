/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:53:23 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/12 19:50:55 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

ch_t *gv;

void	handl(int s)
{
	char	t;

	if (s == SIGUSR1)
	{
		gv->c = gv->c | 0;
	}
	else if (s == SIGUSR2)
	{
		gv->c = gv->c | 1;
	}
	else {
		write(1, "unkown signal ! \n", 18)
	}
	if (gv->shft < 7)
		gv->c = gv->c << 1;
	gv->shft++;
	if (gv->shft == 8)
	{
		t = (char)(gv->c);
		write(1, &t, 1);
		gv->c = 0b00000000;
		gv->shft = 0;
	}
}

int main()
{
	
	gv = (ch_t *)malloc(sizeof(ch_t));
	gv->c = 0b00000000;
	gv->shft = 0;

	pid_t pid;
	signal(SIGUSR1, handl);
	signal(SIGUSR2, handl);
	pid = getpid();
	printf("PID => %d \n", pid);
	while (1)
	{
		sleep(1);
	}

	return (0);
}
