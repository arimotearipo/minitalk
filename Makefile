CLIENTSRC = client.c
SERVERSRC = server.c

CLIENT = client
SERVER = server

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

INCLUDES = libft/libft.h minitalk.h

LIB = -L./libft -lft

PRINT = -L./ft_printf -lftprintf

LIBFT = libft.a

FTPRINTF = ft_printf.a

all:	$(FTPRINTF) $(LIBFT) $(SERVER) $(CLIENT)

$(FTPRINTF):
			@make -C ft_printf

$(LIBFT):
			@make -C libft

$(SERVER):	$(SERVERSRC) $(INCLUDES)
			$(CC) $(FLAGS) $(SERVERSRC) $(LIB) $(PRINT) -o $(SERVER)

$(CLIENT):	$(CLIENTSRC) $(INCLUDES)
			$(CC) $(FLAGS) $(CLIENTSRC) $(LIB) $(PRINT) -o $(CLIENT)

clean:	
		@make fclean -C libft 
		@make fclean -C ft_printf 

fclean:	clean
		$(RM) $(CLIENT) $(SERVER)

re:		fclean all