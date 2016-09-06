# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 12:30:27 by nthibaud          #+#    #+#              #
#    Updated: 2016/04/06 12:30:29 by nthibaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
SRCS = main_ft_cat.c functions.c
OBJS = main_ft_cat.o functions.o
all: $(NAME)
$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRCS)
	@gcc -Wall -Werror -Wextra $(OBJS) -o $(NAME)
clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
