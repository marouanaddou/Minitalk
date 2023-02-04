/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adres.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:00:34 by maddou            #+#    #+#             */
/*   Updated: 2023/02/01 11:25:15 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_print_adres(unsigned long int n, char p)
{
	char	*shexam;
	int		cont;

	cont = 0;
	shexam = "0123456789abcdef";
	if (p == 'p')
	{
		write(1, "0x", 2);
		p = 'a';
		cont = 2;
	}
	if (n >= 16)
	{
		cont += ft_print_adres(n / 16, p);
		cont += ft_print_adres(n % 16, p);
	}
	if (n >= 0 && n < 16)
		cont += ft_putchar(shexam[n]);
	return (cont);
}
