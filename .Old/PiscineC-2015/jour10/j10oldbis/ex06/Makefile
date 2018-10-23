# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fklein <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/05 22:50:08 by fklein            #+#    #+#              #
#    Updated: 2015/11/05 23:45:14 by fklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

FLAGS = -Wall -Wextra -Werror

OPTS = -o $(NAME)

SRC = ft_putchar.c ft_putstr.c ft_ops.c ft_putnbr.c main.c ft_atoi.c

OBJ =

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) $(OPTS)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
