CLIENTSRC = client.c
SERVERSRC = server.c

CLIENT = client
SERVER = server

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

INCLUDES = libft/libft.h minitalk.h

LIB = -L./libft -lft

LIBFT = libft.a

all:	$(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
			@make -C libft

$(SERVER):	$(SERVERSRC) $(INCLUDES)
			$(CC) $(FLAGS) $(SERVERSRC) $(LIB) -o $(SERVER)

$(CLIENT):	$(CLIENTSRC) $(INCLUDES)
			$(CC) $(FLAGS) $(CLIENTSRC) $(LIB) -o $(CLIENT)

clean:
		@make fclean -C libft

fclean:	$(CLEAN)
		$(RM) $(CLIENT) $(SERVER)
