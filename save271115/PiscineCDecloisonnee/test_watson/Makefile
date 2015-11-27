.PHONY: all lib serveur client clean fclean re launch

all: lib
	@make -C src_server
	@make -C src_client

lib:
	@make -C libft

serveur: lib
	@make -C src_server

client: lib
	@make -C src_client

clean:
	@make -C libft clean
	@make -C src_server clean
	@make -C src_client clean
	@rm -rf .tmp

fclean: clean
	@make -C libft fcleana
	@make -C src_server fcleana
	@make -C src_client fcleana

re: fclean all

run:
	./serveur 4242 &
	./client "127.0.0.1" 4242

rr: re
	./serveur 4242 &
	./client "127.0.0.1" 4242

cl: client
	./client "127.0.0.1" 4242

se: serveur
	./serveur 4242 

seb: 
	./serveur 4242 &

l: all
	./serveur 4242 &
	./client "127.0.0.1" 4242
