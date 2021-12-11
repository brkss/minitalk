/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_re.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:46:49 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/11 22:07:45 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	atob(char c, pid_t pid){
	int	b;
	int	t;

	b = (int)c;
	while(b > 0)
	{
		if(b % 2 == 0)
		{
			kill(pid, SIGUSR1);
			write(1, "0", 1);
		}
		else if (b % 2 == 1)
		{
			kill(pid, SIGUSR2);
			write(1, "1", 1);
		}
		b = b / 2;
		usleep(100);
	}
	//kill(pid, SIGUSR1);
}

void	send(char *s, pid_t pid)
{
	int	i;

	i = 0;
	while(s[i])
	{
		atob(s[i], pid);
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
		printf("pid : %d \n", pid);
		s = argv[2];
		send(s, pid);
	}
	else
	{
		write(1, "invalid arguments", 17);
		//atob('a');
	}
	return (0);
}
