/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:47:48 by maddou            #+#    #+#             */
/*   Updated: 2023/02/01 11:27:36 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putchar_hexa(int n, char c)
{
	int		cont;
	char	*shexag;
	char	*shexap;

	cont = 0;
	shexag = "0123456789ABCDEF";
	shexap = "0123456789abcdef";
	if (c == 'x')
		cont += ft_putchar(shexap[n]);
	else if (c == 'X')
		cont += ft_putchar(shexag[n]);
	return (cont);
}

int	ft_print_hexa(unsigned int n, char c)
{
	int	cont;

	cont = 0;
	if (n >= 16)
	{
		cont += ft_print_hexa(n / 16, c);
		cont += ft_print_hexa(n % 16, c);
	}
	if (n >= 0 && n < 16)
		cont += ft_putchar_hexa(n, c);
	return (cont);
}
