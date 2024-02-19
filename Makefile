N_CLIENT = ./client
N_SERVER = ./server

SRC_C = client.c
SRC_S = server.c
OBJ_C = client.o
OBJ_S = server.o
DEP_C = client.d
DEP_S = server.d

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(DEPFLAGS)
DEPFLAGS = -MP -MD

# OBJ_F = obj/


all: $(N_CLIENT) $(N_SERVER)

%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(N_CLIENT): $(OBJ_C)
	$(CC) -o $@ $^

$(N_SERVER): $(OBJ_S)
	$(CC) -o $@ $^


clean:
	rm -f $(OBJ_C) $(OBJ_S)
	
fclean: clean
	rm -f  $(N_CLIENT) $(N_SERVER) $(DEP_C) $(DEP_S)

re: fclean all

.PHONY: all clean fclean re