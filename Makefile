# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 22:54:05 by lcarrizo          #+#    #+#              #
#    Updated: 2024/02/02 18:08:36 by lcarrizo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################    SRCS/DIRECTORES   #############################

NAME		= libftprintf.a
HEADER		= -I ./
SRC		= ft_printf.c ft_printf_utils.c
OBJ		= $(SRC:.c=.o)

#############################    VARIABLES   ##################################

CC		= cc
RM		= rm -rf
OPT		= -c
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs

#############################    TARGETS    ##################################

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(OPT) $(SRC) $(HEADER)
		$(AR) $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		@echo "** clean **"

fclean:		clean
		$(RM) $(NAME)
		@echo "** full clean **"

re:		fclean all

.PHONY:		all clean fclean re
