# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/04 18:58:05 by cchaumar          #+#    #+#              #
#    Updated: 2015/11/04 19:04:52 by cchaumar         ###   ########.fr        #
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
