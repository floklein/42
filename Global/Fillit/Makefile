# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flklein <flklein@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 17:52:37 by flklein           #+#    #+#              #
#    Updated: 2018/11/24 12:09:09 by flklein          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

IDIR = includes -Ilibft/includes
_INC = fillit.h
INC = $(patsubst %,$(IDIR)/%,$(_INC))

SDIR = srcs
ODIR = objs
_SRC = parse.c \
solve.c \
ft_create_elem.c \
ft_list_at.c \
ft_list_push_back.c \
ft_list_size.c \
main.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

OBJ = $(_SRC:.c=.o)
OBJ := $(addprefix $(ODIR)/,$(OBJ))

FLAGS = -Wall -Wextra -Werror
OPTS = -o $(NAME) -I$(IDIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft
		@gcc $(OPTS) $(SRC) libft/libft.a
		@echo "All done."

$(ODIR)/%.o : $(SDIR)/%.c
		@mkdir -p $(ODIR) 2> /dev/null
		@gcc $(FLAGS) -I$(IDIR) -o $@ -c $<
		@echo "Object done."

clean:
		@make -C libft clean
		@rm -rf $(ODIR)
		@echo "Objects cleaned."

fclean: clean
		@make -C libft fclean
		@rm -f $(NAME)
		@echo "Everything cleaned."

re: fclean all
	@make -C libft re
