/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:10:07 by maddou            #+#    #+#             */
/*   Updated: 2023/01/26 18:45:29 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// libft
int	ft_atoi(char *str);
// client
//int main (int argc, char *argv[]);
int *convert_binaire(int b);
int number(int x);

//int main(int sig);
int x(int argc, char *argv[]);

#endif
