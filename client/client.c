/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:43:32 by alel-you          #+#    #+#             */
/*   Updated: 2025/03/20 03:28:50 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	send_char(int pid, char c)
{
	int	x;

	x = 128;
	while (x > 0)
	{
		if (c >= x)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
			c %= x;
			x /= 2;
		}
		else
		{
			if (kill(pid, SIGUSR2))
				exit(EXIT_FAILURE);
			x /= 2;
		}
		usleep(500);
	}
}

static void	msg_converter(char *msg, int pid)
{
	char	octet;
	int		i;

	i = 0;
	octet = 0;
	while (msg[i])
	{
		octet = msg[i];
		send_char(pid, octet);
		octet = 0;
		i++;
	}
	ft_putstr_fd("🥳msg succsfully sent to🥳: ", 1);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3 || !ft_atoi(av[1]))
		return (0);
	pid = ft_atoi(av[1]);
	if (pid == -1)
		return (ft_putstr_fd("Error has occured /-.-\\\n", 1), exit(0), 0);
	if (av[2])
		msg_converter(av[2], pid);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
