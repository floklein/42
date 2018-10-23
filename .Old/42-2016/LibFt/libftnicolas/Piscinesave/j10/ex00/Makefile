# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/18 18:01:32 by nthibaud          #+#    #+#              #
#    Updated: 2016/02/18 18:01:37 by nthibaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_strlen.c srcs/ft_putstr.c \
	 srcs/ft_swap.c srcs/ft_strcmp.c
OBJS = ft_putchar.o ft_strlen.o ft_putstr.o ft_swap.o ft_strcmp.o

all: $(NAME)
$(NAME):
	gcc -Wall -Werror -Wextra -Iincludes -c $(SRCS)
	ar rc libft.a $(OBJS)
	ranlib $(NAME)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
re: fclean all
