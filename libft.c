/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:16:50 by maddou            #+#    #+#             */
/*   Updated: 2023/02/04 15:37:49 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int				i;
	long long int	nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		nb = nb * 10 + str[i++] - 48;
	return ((int)(nb * sign));
}

void	putnbr(int nb)
{
	int long	n;
	int			i;

	n = (long)nb;
	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
	}
	if (n > 9)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	else if (n >= 0 && n <= 9)
	{
		n = n + 48;
		write(1, &n, 1);
	}
}
