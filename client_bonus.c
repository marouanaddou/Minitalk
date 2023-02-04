/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:44:20 by maddou            #+#    #+#             */
/*   Updated: 2023/02/04 17:37:37 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_cont;

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

void	sig_handler(int sig, siginfo_t *information, void *x)
{
	if (sig == SIGUSR1)
		g_cont++;
}

int	main(int argc, char *argv[])
{
	int					i;
	int					b;
	int					j;
	struct sigaction	sig;

	j = 0;
	i = 0;
	sig.sa_sigaction = sig_handler;
	sig.sa_flags = 0;
	sigaction(SIGUSR1, &sig, NULL);
	if (argc == 3)
	{
		while (argv[2][j] != '\0')
			j++;
		while (argv[2][i] != '\0')
		{
			convert_binaire(argv[2][i], argv[1]);
			i++;
		}
		if (j == g_cont)
			write(1, "Message send", 12);
	}
}
