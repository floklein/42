NAME = Fillit
CFLG = -Wextra -Wall -Werror
SRCS = main.c ft_io.c ft_algo.c ft_bits.c -Llibft -lft
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): 
		gcc -o $(NAME) $(CFLG) $(SRCS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
