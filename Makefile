CLIENTSRC = client.c
SERVERSRC = server.c

CLIENTEXE = client
SERVEREXE = server


CC	= gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

c:				$(CLIENTEXE)
				$(CC) $(CFLAGS) $(CLIENTSRC) -o $(CLIENTEXE)

s:				$(SERVEREXE)
				$(CC) $(CFLAGS) $(SERVERSRC) -o $(SERVEREXE)

all:			s c

