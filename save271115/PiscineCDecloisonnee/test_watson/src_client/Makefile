NAME = ../client

FTC =	ft_main.c\
		ft_client.c\
		ft_error.c\
		ft_msg.c\
		ft_cmd.c\
		ft_signal.c\
		ft_tabptr.c

FTO = $(subst .c,.o,$(FTC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@gcc -o $(NAME) $(FTO) ../libft/libft.a
	@echo "\033[32m\nClient created!\033[0m"

%.o: %.c
	@gcc -Wall -Wextra -Werror -I../libft/includes -I./includes -c $<
	@echo "\033[33m.\033[0m\c"

clean:
	@rm -rf $(FTO)
	@echo "\033[33mClient object deleted!\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mClient deleted!\033[0m"

fcleana:
	@rm -rf $(NAME)
	@echo "\033[31mClient deleted!\033[0m"

re: fclean all
