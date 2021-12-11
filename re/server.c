/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_re.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:07:34 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/11 22:19:56 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

ch_t *inf;

void	handl(int sig)
{
	int rx[] = {1, 2, 4, 8, 16, 32, 64, 127, };
	if(sig == SIGUSR1)
	{
		//write(1, "0\n", 2);
	}
	else if(sig == SIGUSR2)
	{
		inf->c += rx[inf->shft];	
		//write(1, "1\n", 2);
	}
	inf->shft ++;
	if(inf->shft == 8)
	{
		//ft_putstr("entered here \n");
		char t = inf->c;
		inf->shft = 0;
		write(1, &t, 1);
		inf->c = 0;
		//printf("c: %d \t index: %d \n", inf->c, inf->shft);
	}
}

int main()
{
	pid_t pid;
	
	signal(SIGUSR1, handl);
	signal(SIGUSR2, handl);
	inf = (ch_t *)malloc(sizeof(ch_t));
	inf->c = 0;
	inf->shft = 0;
	pid = getpid();
	printf("PID => %d \n", pid);
	while(1)
		sleep(1);

	return (0);
}
