#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 17:46:29 by nsavry            #+#    #+#              #
#    Updated: 2015/08/12 18:10:14 by nsavry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FTC = ft_atoi.c\
	  ft_bzero.c\
	  ft_isalnum.c\
	  ft_tabdup.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdup.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strstr.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_putstr.c\
	  ft_itoa.c\
	  ft_memalloc.c\
	  ft_memdel.c\
	  ft_putchar.c\
	  ft_putstr_fd.c\
	  ft_putchar_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_endl.c\
	  ft_putnbr_fd.c\
	  ft_strnew.c\
	  ft_strdel.c\
	  ft_strclr.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strsub.c\
	  ft_strjoin.c\
	  ft_strnjoin.c\
	  ft_strtrim.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strsplit.c\
	  ft_sort_string_tab.c\
	  ft_strstr_bool.c\
	  ft_inv_sort_string_tab.c\
	  ft_get_next_line.c\
	  ft_abs.c\
	  ft_realloc_str_tab.c\
	  ft_isnumber.c\
	  ft_printf_one.c\
	  ft_printf_two.c\
	  ft_printf_three.c\
	  ft_str_tab_len.c\
	  ft_put_str_tab.c\
	  ft_str_tab_dup.c\
	  ft_strsubin.c

FTO = $(subst .c,.o,$(FTC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@ar rc $(NAME) $(FTO)
	@ranlib $(NAME)
	@echo "\033[32m\nLibft created!\033[0m"

%.o: %.c
	@gcc -Wall -Wextra -Werror -I./includes -c $<
	@echo "\033[33m.\033[0m\c"

clean:
	@rm -rf $(FTO)
	@echo "\033[33mLibft object deleted!\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mLibft deleted!\033[0m"

fcleana:
	@rm -rf $(NAME)
	@echo "\033[31mLibft deleted!\033[0m"

re: fclean all
