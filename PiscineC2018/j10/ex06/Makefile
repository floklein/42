# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flklein <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 17:41:26 by flklein           #+#    #+#              #
#    Updated: 2018/09/10 17:42:04 by flklein          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

FLAGS = -Wall -Wextra -Werror

OPTS = -o $(NAME)

SRC = *.c

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) $(SRC) $(OPTS)

fclean:
		@/bin/rm -f $(NAME)

re: fclean all
