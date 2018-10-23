# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/18 18:02:45 by nthibaud          #+#    #+#              #
#    Updated: 2016/02/18 18:15:17 by nthibaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
SRCS = ft_putchar.c ft_putnbr.c ft_putstr.c main.c operations.c functions.c do_op.c
OBJS = ft_putchar.o ft_putnbr.o ft_putstr.o main.o operations.o functions.o do_op.o

all: $(NAME)
$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRCS)
	@gcc -Wall -Werror -Wextra -o $(NAME) $(OBJS)
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
re: fclean all
