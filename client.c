/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddou <maddou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:09:35 by maddou            #+#    #+#             */
/*   Updated: 2023/01/26 18:51:22 by maddou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
int number(int x)
{
	int	cont;

	cont = 0;
	while (x != 0)
	{
		x = x / 2;
		cont++;
	}
	return (cont);
}

int *convert_binaire(int b)
{
    int i;
    int j;
	int *ret;
    int str[8];

    j = number(b);
    i = j + 8 - j;
    while(j > 0)
    {
        str[--i] = b % 2 ;
        b = b / 2;
        j--;    
    }
    while (i > 0 )
      str[--i] = 0;
	ret = str;
    return ret;
}

int main (int argc, char *argv[])
{
	int i;
	int b;
	int j;
	char *str;
	int *binaire;
	
	j = 0;
	i = 0;
	str = argv[2];
	if (argc == 3)
	{
		while(str[j] != '\0')
		{
			binaire = convert_binaire(str[j]);
			while(i < 8)
			{
				if(binaire[i] == 0)
					kill(ft_atoi(argv[1]), (SIGUSR1 - 30));
				else if (binaire[i] == 1)
					kill(ft_atoi(argv[1]), (SIGUSR2 - 30));
				sleep(100);
				i++;
			}
			j++;
		}
	}
}