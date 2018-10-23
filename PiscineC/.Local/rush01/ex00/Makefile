# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flklein <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/09 22:36:11 by flklein           #+#    #+#              #
#    Updated: 2018/09/09 22:42:17 by flklein          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sudoku

FLAGS = -Wall -Wextra -Werror

OPTS = -o $(NAME)

SRC = ft_putchar.c main.c tab.c test.c

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) $(OPTS)

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
