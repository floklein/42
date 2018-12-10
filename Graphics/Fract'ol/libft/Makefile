# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flklein <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 16:18:33 by flklein           #+#    #+#              #
#    Updated: 2018/11/29 17:30:16 by flklein          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

IDIR = includes
_INC = libft.h
INC = $(patsubst %,$(IDIR)/%,$(_INC))

SDIR = .
_SRC = ft_atoi.c \
ft_bzero.c \
ft_convert_base.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_lstadd.c \
ft_lstdel.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstnew.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_nbrlen.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_base.c \
ft_putnbr_base_fd.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strrev.c \
ft_strsplit.c \
ft_strsplitstr.c \
ft_intsplitstr.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_swap.c \
ft_swapchar.c \
ft_tolower.c \
ft_toupper.c \
get_next_line.c \
ft_putstr_int.c \
ft_abs.c \
ft_sqrt_app.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

OBJ = $(_SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
OPTS = -I$(IDIR) -c

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OPTS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(SRC)
	@gcc $(FLAGS) $(OPTS) $(SRC)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
