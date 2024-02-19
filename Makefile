#binaries (executives)
BIN_C = ./client
BIN_S = ./server

SRC_C = $(SRC_F)client.c
SRC_S = $(SRC_F)server.c
OBJ_C = $(OBJ_F)client.o
OBJ_S = $(OBJ_F)server.o

SRC_F = src/
OBJ_F = obj/
PRINTF_F = ft_printf/
LIB = -L$(PRINTF_F) -lftprintf

CC = gcc
#cleate dependencies files to re-make when smth changes in *.h files connected in any of *.c
DEPFLAGS = -MP -MMD
CFLAGS = -Wall -Wextra -Werror $(DEPFLAGS)
FSANITIZE = -fsanitize=address



all: $(BIN_C) $(BIN_S)

$(OBJ_F)%.o: %.c
	@mkdir -p $(OBJ_F)
	$(CC) -c $^ -o $@ $(CFLAGS)

$(BIN_C): $(OBJ_C)
	@cd $(PRINTF_F); make
	$(CC) -o $@ $^ $(LIB) $(FSANITIZE)

$(BIN_S): $(OBJ_S)
	@cd $(PRINTF_F); make
	$(CC) -o $@ $^ $(LIB) $(FSANITIZE)


clean:
	rm -rf $(OBJ_F)
	
fclean: clean
	rm -f  $(BIN_C) $(BIN_S)

re: fclean all

.PHONY: all clean fclean re