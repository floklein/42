# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/23 14:16:45 by nthibaud          #+#    #+#              #
#    Updated: 2016/06/29 16:33:02 by nthibaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SDIR = srcs
_SRCS = ft_putchar.c \
ft_putnbr.c \
ft_putstr.c \
ft_strcat.c \
ft_strcpy.c \
ft_strlen.c \
ft_strncat.c \
ft_strncpy.c \
ft_atoi.c \
ft_itoa.c \
ft_memalloc.c \
ft_memdel.c \
ft_strnew.c \
ft_strdel.c \
ft_strclr.c \
ft_striter.c \
ft_striteri.c \
ft_strmap.c \
ft_strmapi.c \
ft_strequ.c \
ft_strnequ.c \
ft_strcmp.c \
ft_strncmp.c \
ft_strsub.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strsplit.c \
ft_putendl.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_strdup.c \
ft_strlcat.c \
ft_strchr.c \
ft_strrchr.c \
ft_strstr.c \
ft_strnstr.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_toupper.c \
ft_tolower.c \
ft_memccpy.c \
ft_lstadd.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstiter.c \
ft_lstsort_content.c \
ft_lstadd_lastpos.c \
ft_convert_base.c \
ft_sort_wordtab.c
SRCS = $(patsubst %,$(SDIR)/%,$(_SRCS))
OBJS = $(_SRCS:.c=.o)
all: $(NAME)
$(NAME): $(SRCS)
	@gcc -Wall -Werror -Wextra -Iincludes -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "gcc / ar rc / ranlib"
clean:
	@rm -f $(OBJS)
	@echo "cleaned"
fclean: clean
	@rm -f $(NAME)
re: fclean all
