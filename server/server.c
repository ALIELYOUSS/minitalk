/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:30:12 by alel-you          #+#    #+#             */
/*   Updated: 2025/03/19 04:36:59 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handler(int signum, siginfo_t *info, void *none)
{
	static unsigned int	c;
	static int			bits;
	static int			pre;

	(void)none;
	if (signum == SIGINT)
	{
		ft_putstr_fd("\nyou have stoped the process 🤐!!\n", 1);
		exit(0);
	}
	if (pre != 0 && pre != info->si_pid)
	{
		c = 0;
		bits = 0;
	}
	pre = info->si_pid;
	if (signum == SIGUSR1)
	{
		c = (c << 1) | 1;
		bits++;
	}
	if (signum == SIGUSR2)
	{
		c = (c << 1) | (0);
		bits++;
	}
	if (bits == 8)
	{
		write(1, &c, 1);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_flags = (SA_SIGINFO | SA_RESTART);
	sig.sa_sigaction = handler;
	sigemptyset(&sig.sa_mask);
	ft_putstr_fd("👻PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		if (sigaction(SIGINT, &sig, NULL) == -1 || \
			sigaction(SIGUSR2, &sig, NULL) == -1 || \
			sigaction(SIGUSR1, &sig, NULL) == -1)
		{
			perror("\n\n\nError🙄\n\n\n");
			exit(0);
		}
		pause();
	}
}
