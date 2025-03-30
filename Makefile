CLIENT_SRC = client.c client_utils.c
SERVER_SRC = server.c server_utils.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME_1 = client
NAME_2 = server

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(CLIENT_OBJ)
	@$(CC) $(CLIENT_OBJ) -o $(NAME_1)

$(NAME_2): $(SERVER_OBJ)
	@$(CC) $(SERVER_OBJ) -o $(NAME_2)

clean:
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	@rm -f $(NAME_1) $(NAME_2)

re: fclean all

.PHONY: all clean re fclean
