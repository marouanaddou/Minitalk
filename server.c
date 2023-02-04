/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:05:51 by maddou            #+#    #+#             */
/*   Updated: 2023/02/04 19:33:29 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *information, void *x)
{
	int			ip;
	static int	j;
	static char	str;

	if (ip != information->si_pid)
	{
		j = 0;
		str = 0;
	}
	if (sig == SIGUSR2)
		str = str | (1 << j);
	j++;
	if (j == 8)
	{
		write(1, &str, 1);
		j = 0;
		str = 0;
	}
	ip = information->si_pid;
}

int	main(void)
{
	struct sigaction	sig;

	putnbr(getpid());
	write(1, "\n", 1);
	sig.sa_sigaction = sig_handler;
	sig.sa_flags = 0;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		;
}
