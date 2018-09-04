# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/01 15:23:22 by cdesvern          #+#    #+#              #
#    Updated: 2015/11/01 15:48:40 by cdesvern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
FLAGS = -Wall -Wextra -Werror
OPTS = -o
SRC = main.c ft_gardening.c ft_make_tree.c ft_ops.c ft_putnbr.c ft_putchar.c\
	  ft_atoi.c ft_strlen.c

all: $(NAME)

$(NAME): 
	gcc $(FLAGS) $(SRC) $(OPTS) $(NAME)

clean:


fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
