# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsmite <dwight.smite@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/02 13:34:26 by dsmite            #+#    #+#              #
#*   Updated: 2016/04/30 16:35:13 by dsmite           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fillit
SDIR = srcs
IDIR = inc
_INC = fillit.h
INC = $(patsubst %,$(IDIR)/%,$(_INC))
_SRC = main.c check_file.c stock_tetri.c stock_tetri2.c solver.c \
	print_result.c ft_putchar.c ft_putstr.c ft_putendl.c ft_bzero.c \
	solver_utils.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))
OBJS = $(_SRC:.c=.o)
GCCFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	@gcc $(GCCFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRC)
	@gcc $(GCCFLAGS) -c $(SRC)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
