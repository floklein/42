NAME = ft_cat
FLAG = -Wextra -Werror -Wall
SRCS = main.c print.c
OBJS = main.o print.o
OPTS = -o $(NAME)

all : $(NAME)

$(NAME):
	gcc $(OPTS) $(FLAG) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
