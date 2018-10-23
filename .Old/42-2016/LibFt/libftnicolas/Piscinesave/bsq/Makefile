# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fklein <fklein@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/20 18:24:52 by fklein            #+#    #+#              #
#    Updated: 2016/04/20 18:48:22 by fklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = main.c tools.c tools2.c lists.c bsq.c

OBJS = main.o tools.o tools2.o lists.o bsq.o

FLAGS = -Werror -Wall -Wextra

OPT = -o $(NAME)

all : $(NAME)

$(NAME) :
	gcc $(OPT) $(FLAGS) $(SRCS)

clean	:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re		: fclean all
