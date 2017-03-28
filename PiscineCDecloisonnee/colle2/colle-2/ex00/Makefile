# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fklein <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/01 18:53:15 by fklein            #+#    #+#              #
#    Updated: 2015/11/01 20:00:44 by fklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

SRC = colle00.c colle01.c colle02.c colle03.c colle04.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_simple_atoi.c ft_strcmp.c ft_strlen.c main.c success.c successbonus.c

FLAG = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRC) -o $(NAME)

clean:
	
fclean: clean
	rm -f $(NAME)

re: fclean all
