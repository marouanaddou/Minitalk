# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maddou <maddou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 18:18:53 by maddou            #+#    #+#              #
#    Updated: 2023/01/26 18:23:31 by maddou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -rf
CFLAGC = -Wall -Wextra -Werror
SRC_C = client.c libft.c
SRC_S = server.c  libft.c

OBJ_C = $(SRC_C:.c=.o)

OBJ_S = $(SRC_S:.c=.o)

NAME = client
PROGRAM = server

%.o : %.c minitalk.h
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME) $(PROGRAM)

$(PROGRAM) : $(OBJ_S)
	@$(CC) $(CFLAGC) $(OBJ_S) -o $@

$(NAME) : $(OBJ_C)
	@$(CC) $(CFLAGS) $(OBJ_C) -o $@
clean :
	@$(RM) $(OBJ_C) $(OBJ_S)
fclean : clean
	@$(RM) $(PROGRAM) $(NAME)
re : fclean all
.PHONY : all fclean clean re
