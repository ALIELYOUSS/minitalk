/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_uils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:29:23 by alel-you          #+#    #+#             */
/*   Updated: 2025/03/12 15:29:33 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char const *str)
{
	int		i;
	int		sign;
	long	tmp;

	i = 0;
	sign = 1;
	tmp = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_check_overflow(tmp, str[i], sign))
			return (ft_check_overflow(tmp, str[i], sign));
		tmp = (tmp * 10) + (str[i] - '0');
		i++;
	}
	tmp *= sign;
	return (tmp);
}