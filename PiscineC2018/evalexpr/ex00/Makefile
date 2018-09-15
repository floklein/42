# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flklein <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 17:41:26 by flklein           #+#    #+#              #
#    Updated: 2018/09/15 19:21:33 by flklein          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

IDIR = includes
_INC = eval_expr.h
INC = $(patsubst %,$(IDIR)/%,$(_INC))

SDIR = srcs
_SRC = *.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

OBJ = $(_SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
OPTS = -o $(NAME) -I$(IDIR)

all: $(NAME)

$(NAME): $(OBJ)
		@gcc $(FLAGS) $(OPTS) $(SRC)

$(OBJ): $(SRC)
		@gcc -c -I$(IDIR) $(SRC)

clean: fclean
		@/bin/rm -f $(OBJ)

fclean:
		@/bin/rm -f $(NAME)

re: clean all
