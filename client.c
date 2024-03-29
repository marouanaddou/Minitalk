/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:09:35 by maddou            #+#    #+#             */
/*   Updated: 2023/02/04 19:36:27 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_binaire(int b, char *pid)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	while (i <= 7)
	{
		r = b & 1;
		if (r == 0)
			kill(ft_atoi(pid), SIGUSR1);
		else if (r == 1)
			kill(ft_atoi(pid), SIGUSR2);
		b = b >> 1;
		usleep(200);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	b;
	int	j;

	j = 0;
	i = 0;
	if (argc == 3)
	{
		while (argv[2][i] != '\0')
		{
			convert_binaire(argv[2][i], argv[1]);
			i++;
		}
	}
}
