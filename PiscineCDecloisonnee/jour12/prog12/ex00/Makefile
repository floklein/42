# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fklein <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/06 01:35:43 by fklein            #+#    #+#              #
#    Updated: 2015/11/06 01:36:46 by fklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

FLAGS = -Wall -Wextra -Werror

OPTS = -o $(NAME)

SRC = ft_putchar.c ft_putstr.c main.c

OBJ =

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) $(OPTS)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
