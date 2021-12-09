/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:53:23 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/09 21:58:32 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

typedef struct ch_s {
	int c;
	int shft;
} ch_t;

ch_t *gv;


//int c = 0b00000000;
//int shft = 0;

int reverse(int b) {
   b = (b & 0b11110000) >> 4 | (b & 0b00001111) << 4;
   b = (b & 0b11001100) >> 2 | (b & 0b00110011) << 2;
   b = (b & 0b10101010) >> 1 | (b & 0b01010101) << 1;
   return b;
}

void	handl(int s)
{
	char	t;

	if(s == SIGUSR1)
	{
		// 0
		gv->c = gv->c | 0;
	}
	else if(s == SIGUSR2)
	{
		// 1
		gv->c = gv->c | 1;
	}
	else {
		//printf("unknown signal ! \n");
	}
	if(gv->shft < 7)
		gv->c = gv->c << 1;
	gv->shft++;
	if(gv->shft == 8)
	{
		gv->c = reverse(gv->c);
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
	while(1)
	{
		sleep(1);
	}

	return (0);
}
