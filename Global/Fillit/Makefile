# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flklein <flklein@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 17:52:37 by flklein           #+#    #+#              #
#    Updated: 2018/11/23 18:10:21 by flklein          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

IDIR = includes -Ilibft/includes
_INC = fillit.h
INC = $(patsubst %,$(IDIR)/%,$(_INC))

SDIR = srcs
_SRC = parse.c \
ft_create_elem.c \
ft_list_at.c \
ft_list_push_back.c \
ft_list_size.c \
ft_list_foreach.c \
main.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

OBJ = $(_SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
OPTS = -o $(NAME) -I$(IDIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft/ re
		@gcc $(FLAGS) $(OPTS) $(SRC) libft/libft.a

$(OBJ): $(SRC)
		@gcc -c -I$(IDIR) $(SRC)

clean:
		@make -C libft/ clean
		@/bin/rm -f $(OBJ)

fclean: clean
		@make -C libft/ fclean
		@/bin/rm -f $(NAME)

re: clean all
