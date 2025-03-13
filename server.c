/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:30:12 by alel-you          #+#    #+#             */
/*   Updated: 2025/03/12 18:08:09 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int signum)
{
    static unsigned char c;
    static int bits;

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
        bits = 0;
        c = 0;
    }
}

int main()
{
    printf("PID: %d\n", getpid());
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (1)
    {
        pause();
    }
    
}