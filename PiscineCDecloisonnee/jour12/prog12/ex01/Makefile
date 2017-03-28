# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fklein <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/06 01:35:43 by fklein            #+#    #+#              #
#    Updated: 2015/11/06 02:37:43 by fklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

FLAGS = -Wall -Wextra -Werror

OPTS = -o $(NAME)

SRC = ft_putchar.c ft_putchar_error.c ft_putstr.c ft_putstr_error.c main.c

OBJ =

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) $(OPTS)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
