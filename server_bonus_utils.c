/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:21:02 by maddou            #+#    #+#             */
/*   Updated: 2023/02/04 19:35:05 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_write(t_info *info)
{
	write(1, &(*info).str[0], 1);
	write(1, &(*info).str[1], 1);
	if ((*info).i == 24)
		write(1, &(*info).str[2], 1);
	else if ((*info).i == 32)
	{
		write(1, &(*info).str[2], 1);
		write(1, &(*info).str[3], 1);
	}
}

void	print(t_info *info)
{
	if ((*info).i == 24)
	{
		(*info).str[2] = (*info).c;
		(*info).c = 0;
		if ((*info).cont == 3)
		{
			ft_write(info);
			(*info).i = 0;
		}
		(*info).j = 0;
	}
	else if ((*info).i == 32)
	{
		(*info).str[3] = (*info).c;
		(*info).c = 0;
		ft_write(info);
		(*info).i = 0;
		(*info).j = 0;
	}
}

void	chek(t_info *info)
{
	if ((*info).i == 8)
	{
		(*info).cont = ft_chek((*info).c);
		if ((*info).cont == 0)
		{
			write(1, &(*info).c, 1);
			(*info).i = 0;
		}
		else
			(*info).str[0] = (*info).c;
		(*info).c = 0;
		(*info).j = 0;
	}
	else if ((*info).i == 16)
	{
		(*info).str[1] = (*info).c;
		if ((*info).cont == 2)
		{
			ft_write(info);
			(*info).i = 0;
		}
		(*info).c = 0;
		(*info).j = 0;
	}
	print(info);
}
