/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:10:07 by maddou            #+#    #+#             */
/*   Updated: 2023/02/04 12:40:54 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_info
{
	int		ip;
	int		i;
	int		j;
	int		*stacka;
	char	c;
	char	str[4];
	int		cont;
}			t_info;

// libft
int			ft_atoi(char *str);
// ft_printf
int			ft_print_adres(unsigned long int n, char p);
int			ft_print_digit(int nb);
int			ft_print_hexa(unsigned int n, char c);
int			ft_print_string(char *str);
int			ft_print_unsigned(unsigned int u);
int			ft_printf(const char *str, ...);
int			ft_putchar(char c);
// client
//int main (int argc, char *argv[]);
void		convert_binaire(int b, char *pid);
int			number(int x);

//int main(int sig);
int			x(int argc, char *argv[]);
void		putnbr(int nb);
int			ft_chek(char str);
void		chek(t_info *info);
#endif