/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:30:12 by alel-you          #+#    #+#             */
/*   Updated: 2025/03/17 02:32:12 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void signal_handler(int signum)
{
    static unsigned char c;
    static int bits;

    // ft_putnbr_fd(bits, 1);
    c = 0;
    bits = 0;
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

int main()
{
    struct sigaction sig;

    sig.__sigaction_u.__sa_handler = signal_handler;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = 0;
    ft_putstr_fd("PID: ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd('\n', 1);
    sigaction(SIGINT, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    sigaction(SIGUSR1, &sig, NULL);
    while (1);
}