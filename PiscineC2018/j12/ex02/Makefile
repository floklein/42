# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flklein <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 15:01:32 by flklein           #+#    #+#              #
#    Updated: 2018/09/20 14:54:33 by flklein          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail

IDIR = includes
_INC = ft_cat.h
INC = $(patsubst %,$(IDIR)/%,$(_INC))

SDIR = srcs
_SRC = error.c ft_abs.c ft_atoi.c ft_putchar.c ft_putchar_err.c ft_putstr.c \
	ft_putstr_err.c ft_strcmp.c ft_strjoin.c ft_strlen.c is_numeric.c main.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

OBJ = $(_SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -fsanitize=address
OPTS = -o $(NAME) -I$(IDIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		@gcc $(FLAGS) $(OPTS) $(SRC)

$(OBJ): $(SRC)
		@gcc -c -I$(IDIR) $(SRC)

clean:
		@/bin/rm -f $(OBJ)

fclean: clean
		@/bin/rm -f $(NAME)

re: clean all
