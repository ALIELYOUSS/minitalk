/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:29:23 by alel-you          #+#    #+#             */
/*   Updated: 2025/03/20 03:45:56 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s && fd >= 0)
	{
		write(fd, s, ft_strlen(s));
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	tmp;

	if (fd < 0)
		return ;
	tmp = n;
	if (tmp == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (tmp < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = -tmp;
	}
	if (tmp > 9)
	{
		ft_putnbr_fd(tmp / 10, fd);
	}
	ft_putchar_fd((tmp % 10) + '0', fd);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}
