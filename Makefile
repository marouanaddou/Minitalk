# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maddou <maddou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 18:18:53 by maddou            #+#    #+#              #
#    Updated: 2023/02/04 12:42:30 by maddou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -rf
CFLAGC = -Wall -Wextra -Werror
SRC_C = client.c libft.c \
				ft_printf.c             ft_putchar.c \
				ft_print_digit.c        ft_print_unsigned.c \
				ft_print_hexa.c         ft_print_string.c \
				ft_print_adres.c
SRC_S = server.c  libft.c \
 ft_printf.c             ft_putchar.c \
				ft_print_digit.c        ft_print_unsigned.c \
				ft_print_hexa.c         ft_print_string.c \
				ft_print_adres.c
SRC_BONUS_C = client_bonus.c libft.c \
					ft_printf.c             ft_putchar.c \
					ft_print_digit.c        ft_print_unsigned.c \
					ft_print_hexa.c         ft_print_string.c \
					ft_print_adres.c
SRC_BONUS_S = server_bonus.c libft.c \
					ft_printf.c             ft_putchar.c \
					ft_print_digit.c        ft_print_unsigned.c \
					ft_print_hexa.c         ft_print_string.c \
					ft_print_adres.c         server_bonus_utils.c

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)

OBJ_BONUS_C = $(SRC_BONUS_C:.c=.o)
OBJ_BONUS_S = $(SRC_BONUS_S:.c=.o)

NAME = client
PROGRAM = server

NAME_BONUS = client_bonus
PROGRAM_BONUS = server_bonus

%.o : %.c minitalk.h
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME) $(PROGRAM)
$(PROGRAM) : $(OBJ_S)
	@$(CC) $(CFLAGC) $(OBJ_S) -o $@

$(NAME) : $(OBJ_C)
	@$(CC) $(CFLAGS) $(OBJ_C) -o $@

bonus : $(NAME_BONUS) $(PROGRAM_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS_C)
	@$(CC) $(CFLAGS) $(OBJ_BONUS_C) -o $@

$(PROGRAM_BONUS) : $(OBJ_BONUS_S)
	@$(CC) $(CFLAGS) $(OBJ_BONUS_S) -o $@
	


clean :
	@$(RM) $(OBJ_C) $(OBJ_S) $(OBJ_BONUS_C) $(OBJ_BONUS_S)

fclean : clean
	@$(RM) $(PROGRAM) $(NAME) $(NAME_BONUS) $(PROGRAM_BONUS)

re : fclean all

.PHONY : all fclean clean re
