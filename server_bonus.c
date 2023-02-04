/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:44:09 by maddou            #+#    #+#             */
/*   Updated: 2023/02/04 19:33:15 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_chek(char str)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	j = 7;
	while (i <= 7)
	{
		r = str & (1 << j);
		if (r == 0)
			return (i);
		i++;
		j--;
	}
	return (i);
}

// void	convert(char *nb)
// {
// 	int	i;
// 	int	p;
// 	int	result;

// 	i = 7;
// 	result = 0;
// 	while (i >= 0)
// 	{
// 		p = produit(i);
// 		result += p * (nb[i] - 48);
// 		i--;
// 	}
// 	ft_printf("%c", result);
// }

void	sig_handler(int sig, siginfo_t *information, void *x)
{
	t_info	info;

	if (info.ip != information->si_pid)
	{
		info.j = 0;
		info.c = 0;
		info.i = 0;
		info.cont = 0;
	}
	if (sig == SIGUSR2)
		info.c = info.c | (1 << info.j);
	info.j++;
	info.i++;
	chek(&info);
	info.ip = information->si_pid;
	if (info.j == 7)
		kill(information->si_pid, SIGUSR1);
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
