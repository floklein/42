# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 12:30:37 by nthibaud          #+#    #+#              #
#    Updated: 2016/04/06 12:30:39 by nthibaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail
SRCS = main.c option.c option2.c ft_tail.c error.c functions.c
OBJS = main.o option.o option2.o ft_tail.o error.o functions.o
all: $(NAME)
$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRCS)
	@gcc -Wall -Werror -Wextra $(OBJS) -o $(NAME)
clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
