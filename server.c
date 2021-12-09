/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:53:23 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/09 15:07:22 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"
/*
typedef struct ch_s {
	int c;
	int shft;
} ch_t;

ch_t *gv;
*/

int c = 0b00000000;
int shft = 0;

int reverse(int b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}

void	handl(int s)
{
	if(s == SIGUSR1)
	{
		// 0
		c = c | 0;
	}
	else if(s == SIGUSR2)
	{
		// 1
		c = c | 1;
	}
	else {
		//printf("unknown signal ! \n");
	}
	if(shft < 7)
		c = c << 1;
	shft++;
	if(shft == 8)
	{
		c = reverse(c);
		char t = (char) c;
		write(1, &t, 1);
		//printf("%c", (char)(c));
		c = 0b00000000;
		shft = 0;
	}
	//gv->shft = gv->shft + 1 - 1;
	//printf("%d \n", shft);
}

int main()
{
/*	
	gv = (ch_t *)malloc(sizeof(ch_t));
	gv->c = 0b00000000;
	gv->shft = 0;
*/
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
