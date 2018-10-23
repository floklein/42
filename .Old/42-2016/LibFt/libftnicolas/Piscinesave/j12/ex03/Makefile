# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 12:30:47 by nthibaud          #+#    #+#              #
#    Updated: 2016/04/06 12:30:51 by nthibaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump
SRCS = main.c ft_hexdump.c ft_hexdump_opt.c display.c display_opt.c conv.c \
	ft_convert_base.c ft_strcmp.c ft_strcpy.c ft_hexdump_input.c \
	display_input.c ft_hexdump_input_opt.c display_input_opt.c error.c \
	check_files_hex.c check_files_opt.c functions.c 
OBJS = main.o ft_hexdump.o ft_hexdump_opt.o display.o display_opt.o conv.o \
	ft_convert_base.o ft_strcmp.o ft_strcpy.o ft_hexdump_input.o \
	display_input.o ft_hexdump_input_opt.o display_input_opt.o error.o \
	check_files_hex.o check_files_opt.o functions.o
all: $(NAME)
$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRCS)
	@gcc -Wall -Werror -Wextra $(OBJS) -o $(NAME)
clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
