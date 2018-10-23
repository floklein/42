# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fklein <fklein@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/04 18:33:07 by fklein            #+#    #+#              #
#    Updated: 2016/09/04 18:33:45 by fklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
INC = get_next_line.h
SRC = get_next_line.c libft/ft_strclr.c libft/ft_strjoin.c
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
