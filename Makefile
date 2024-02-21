GREEN = \033[0;32m
MAGENTA	= \033[0;35m
YELLOW = \033[0;33m
RESET_COLOR = \033[0m

#binaries (executives)
BIN_C = ./client
BIN_S = ./server

SRC_C = client.c
SRC_S = server.c ascii_draw_minitalk.c
OBJ_C = $(OBJ_F)client.o
OBJ_S = $(OBJ_F)server.o $(OBJ_F)ascii_draw_minitalk.o

VPATH = src/
OBJ_F = obj/

LIBFT = libft
LIBFLAGS = -L$(LIBFT) -lft

CC = gcc
#cleate dependencies files to re-make when smth changes in *.h files connected in any of *.c
DEPFLAGS = -MP -MMD
CFLAGS = -Wall -Wextra -Werror -g $(DEPFLAGS)
FSANITIZE = -fsanitize=address


.SILENT:
all: $(BIN_C) $(BIN_S)


$(BIN_C): $(OBJ_C)
	$(MAKE) -C $(LIBFT);
	$(CC) -o $@ $^ $(LIBFLAGS) $(FSANITIZE)
	@echo "$(GREEN)Client$(RESET_COLOR)"

$(BIN_S): $(OBJ_S)
	$(MAKE) -C $(LIBFT);
	$(CC) -o $@ $^ $(LIBFLAGS) $(FSANITIZE)
	@echo "$(GREEN)Server$(RESET_COLOR)"

$(OBJ_F)%.o: %.c
	mkdir -p $(@D)
	$(CC) -c $^ -o $@ $(CFLAGS) $(FSANITIZE)

clean:
	clear;
	rm -rf $(OBJ_F)
	@echo "$(YELLOW)\n☓  CLEAN MINITALK$(RESET_COLOR)"
	cd $(LIBFT) && make fclean; 
#how to rewrite it like the same syntax i did make
	
fclean: clean
	rm -f  $(BIN_C) $(BIN_S)
	@echo "$(YELLOW)☓☓ FCLEAN MINITALK\n$(RESET_COLOR)"

re: fclean all


.PHONY: all clean fclean re