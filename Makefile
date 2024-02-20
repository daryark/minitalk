GREEN = \033[0;32m
MAGENTA	= \033[0;35m
YELLOW = \033[0;33m
RESET_COLOR = \033[0m

#binaries (executives)
BIN_C = ./client
BIN_S = ./server

SRC_C = client.c
SRC_S = server.c
OBJ_C = $(OBJ_F)client.o
OBJ_S = $(OBJ_F)server.o

VPATH = src/
OBJ_F = obj/

LIBFT = libft

LIB = $(LIBFT)
LIBFLAGS = -L$(LIBFT) -lft

CC = gcc
#cleate dependencies files to re-make when smth changes in *.h files connected in any of *.c
DEPFLAGS = -MP -MMD
CFLAGS = -Wall -Wextra -Werror -g $(DEPFLAGS)
FSANITIZE = -fsanitize=address


.SILENT:
all: minitalk

$(BIN_C): $(OBJ_C)
	$(MAKE) -C $(LIB);
	$(CC) -o $@ $^ $(LIBFLAGS) $(FSANITIZE)

$(BIN_S): $(OBJ_S)
	$(MAKE) -C $(LIB);
	$(CC) -o $@ $^ $(LIBFLAGS) $(FSANITIZE)

$(OBJ_F)%.o: %.c
	mkdir -p $(@D)
	$(CC) -c $^ -o $@ $(CFLAGS) $(LIBFLAGS) $(FSANITIZE)

clean:
	rm -rf $(OBJ_F)
	@echo "$(YELLOW)\n☓ CLEAN MINITALK$(RESET_COLOR)"
	cd $(LIB) && make fclean; 
#how to rewrite it like the same syntax i did make
	
fclean: clean
	rm -f  $(BIN_C) $(BIN_S)
	@echo "$(YELLOW)☓☓ FCLEAN MINITALK\n$(RESET_COLOR)"

re: fclean all

.PHONY: all clean fclean re

minitalk: $(BIN_C) $(BIN_S)
	@echo "$(YELLOW)\
 \n———————————————————————————————————————————————————————————————————————————————————————————\n\
 \n  ☻       ☻    ☻ ☻   ☻ ☻      ☻ ☻   ☻ ☻   ☻ ☻ ☻ ☻ ☻ ☻     ☻ ☻ ☻ ☻     ☻ ☻       ☻ ☻    ☻   \
 \n ☻ ☻     ☻ ☻   ☻ ☻   ☻ ☻ ☻    ☻ ☻   ☻ ☻       ☻ ☻       ☻ ☻     ☻ ☻   ☻ ☻       ☻ ☻  ☻     \
 \n ☻ ☻ ☻ ☻ ☻ ☻   ☻ ☻   ☻ ☻  ☻   ☻ ☻   ☻ ☻  ✨   ☻ ☻       ☻ ☻ ☻ ☻ ☻ ☻   ☻ ☻       ☻ ☻ ☻      \
 \n ☻ ☻     ☻ ☻   ☻ ☻   ☻ ☻    ☻ ☻ ☻   ☻ ☻       ☻ ☻       ☻ ☻     ☻ ☻   ☻ ☻       ☻ ☻  ☻     \
 \n ☻ ☻     ☻ ☻   ☻ ☻   ☻ ☻      ☻ ☻   ☻ ☻       ☻ ☻       ☻ ☻     ☻ ☻   ☻ ☻ ☻ ☻   ☻ ☻    ☻   \n\
 \n———————————————————————————————————————————————————————————————————————————————————————————\
		$(RESET_COLOR)"