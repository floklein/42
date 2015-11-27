NAME = ../serveur

FTC =	ft_main.c\
		ft_server.c\
		ft_tabptr.c\
		ft_cmd.c\
		ft_msg.c\
		ft_path.c\
		ft_error.c\
		ft_signal.c

FTO = $(subst .c,.o,$(FTC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@gcc -o $(NAME) $(FTO) ../libft/libft.a
	@echo "\033[32m\nServeur created!\033[0m"

%.o: %.c
	@gcc -Wall -Wextra -Werror -I../libft/includes -I./includes -c $<
	@echo "\033[33m.\033[0m\c"

clean:
	@rm -rf $(FTO)
	@echo "\033[33mServeur object deleted!\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mServeur deleted!\033[0m"

fcleana:
	@rm -rf $(NAME)
	@echo "\033[31mServeur deleted!\033[0m"

lib:
	@make -C ../libft

re: fclean all
