# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 22:54:05 by lcarrizo          #+#    #+#              #
#    Updated: 2024/02/02 09:43:51 by lcarrizo          ###   ##london.com      #
#                                                                              #
# **************************************************************************** #

############################    SRCS/DIRECTORES   #############################

NAME		= libftprintf.a
HEADER		= -I ./
SRC		= ft_printf.c ./src/manage_numbers.c ./src/manage_strings.c
OBJ		= $(src:.c=.o)

#############################    VARIABLES   ##################################

CC		= cc
RM		= rm -rf
OPT		= -c
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs

#############################    TARGETS    ##################################

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(OPT) $(SRC)
		$(AR) $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		@echo: "** clean **"

fclean:		clean
		$(RM) $(NAME)
		@echo "** full clean **"

re:		fclean all

.PHONY:		all clean fclean re

