/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:53:28 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/13 01:16:08 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	SIGUSR1 -> 0
	SIGUSR2 -> 1
*/

#include "../includes/minitalk.h"

int	check_bit(char c, int shift)
{
	int	b;
	int	k;

	b = 0b10000000 >> shift;
	k = b & c;
	return (k);
}

void	send_s(char *message, pid_t pid)
{
	int	i;
	int	sh;

	i = 0;
	while (message[i])
	{
		sh = 0;
		while (sh < 8)
		{
			if (check_bit(message[i], sh) != 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			sh++;
		}
		i++;
	}
}

void	conf(int sig)
{
	(void)sig;
	write(1, "signal received !\n", 18);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*s;

	signal(SIGUSR1, conf);
	if (argc > 2)
	{
		pid = ft_atoi(argv[1]);
		s = argv[2];
		send_s(s, pid);
	}
	else
	{
		printf("not enough arguments !\n");
	}
	return (0);
}
