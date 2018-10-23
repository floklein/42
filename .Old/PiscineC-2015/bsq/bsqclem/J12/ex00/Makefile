NAME = ft_display_file
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
