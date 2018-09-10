# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flklein <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 17:41:26 by flklein           #+#    #+#              #
#    Updated: 2018/09/10 23:59:09 by flklein          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

IDIR = includes
_INC = do_op.h
INC = $(patsubst %,$(IDIR)/%,$(_INC))

SDIR = srcs
_SRC = ft_atoi.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strcpy.c ft_strlen.c\
	ft_strstr.c main.c operations.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

FLAGS = -Wall -Wextra -Werror
OPTS = -o $(NAME) -I $(IDIR)

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) $(SRC) $(OPTS)

clean:
		@/bin/rm -f $(NAME)

re: clean all
