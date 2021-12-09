/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:53:28 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/09 15:08:15 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SIGUSR1 -> 0
// SIGUSR2 -> 1

#include "./includes/minitalk.h"

int	check_bit(char c, int shift)
{
	int b = 0b00000001 << shift;
	int k = b & c;
	return (k);
}

void send_s(char *message, pid_t pid)
{
	int i;
	int sh;

	i = 0;
	while(message[i])
	{
		sh = 0;
		while (sh < 8)
		{
			if (check_bit(message[i], sh) >> sh == 1)
			{
				printf("Bit [%d] is %d \n", sh, 1);
				kill(pid, SIGUSR2);
			} else {
				printf("Bit [%d] is %d \n", sh, 0);
				kill(pid, SIGUSR1);
			} 
			usleep(100);			
			sh++;	
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	pid_t	pid;
	char	*s;
	
	if(argc > 2)
	{
		pid = atoi(argv[1]);
		s = argv[2];
		send_s(s, pid);
	}
	else {
		printf("not enough arguments !\n");
	}
	
	return (0);
}
