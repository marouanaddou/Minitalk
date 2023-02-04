/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:31:32 by maddou            #+#    #+#             */
/*   Updated: 2023/02/01 11:26:56 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_print_digit(int nb)
{
	long	n;
	int		cont;

	cont = 0;
	n = (long)nb;
	if (n < 0)
	{
		n = n * -1;
		cont += ft_putchar('-');
	}
	if (n > 9)
	{
		cont += ft_print_digit(n / 10);
		cont += ft_print_digit(n % 10);
	}
	if (n >= 0 && n <= 9)
		cont += ft_putchar(n + 48);
	return (cont);
}
