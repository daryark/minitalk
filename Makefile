GREEN = \033[0;32m
MAGENTA	= \033[0;35m
YELLOW = \033[0;33m
RESET_COLOR = \033[0m

#binaries (executives)
BIN_C = client
BIN_S = server

BIN_C_BONUS = client_bonus
BIN_S_BONUS = server_bonus

#srcs objs
SRC_C = client.c
SRC_S = server.c ascii_draw_minitalk.c
OBJ_C = $(OBJ_F)client.o
OBJ_S = $(addprefix $(OBJ_F), $(SRC_S:%.c=%.o))

SRC_C_BONUS = client_bonus.c
SRC_S_BONUS = server_bonus.c ascii_draw_minitalk.c
OBJ_C_BONUS = $(OBJ_F)client_bonus.o
OBJ_S_BONUS = $(addprefix $(OBJ_F), $(SRC_S_BONUS:%.c=%.o))
#add path and folders
VPATH = src/
OBJ_F = obj/
#libs
LIBFT = libft
LIBFLAGS = -L$(LIBFT) -lft

CC = gcc
#cleate dependencies files to re-make when smth changes in *.h files connected in any of *.c
DEPFLAGS = -MP -MMD
CFLAGS = -Wall -Wextra -Werror -g $(DEPFLAGS)
FSANITIZE = -fsanitize=address

#make all the commands run for silence, not shown, only echo messages
.SILENT:
all: $(BIN_C) $(BIN_S)


$(BIN_C): $(OBJ_C)
	$(MAKE) -C $(LIBFT);
	$(CC) -o $@ $^ $(LIBFLAGS) $(FSANITIZE)
	@echo "$(GREEN)Client$(RESET_COLOR)"

$(BIN_S): $(OBJ_S)
	$(MAKE) -C $(LIBFT);
	$(CC) -o $@ $^ $(LIBFLAGS) $(FSANITIZE)
	@echo "$(GREEN)Server\n$(RESET_COLOR)"

$(OBJ_F)%.o: %.c
	mkdir -p $(@D)
	$(CC) -c $^ -o $@ $(CFLAGS) $(FSANITIZE)

bonus: $(BIN_C_BONUS) $(BIN_S_BONUS)

$(BIN_C_BONUS): $(OBJ_C_BONUS)
	$(MAKE) -C $(LIBFT);
	$(CC) -o $@ $^ $(LIBFLAGS) $(FSANITIZE)
	@echo "$(GREEN)Client bonus$(RESET_COLOR)"

$(BIN_S_BONUS): $(OBJ_S_BONUS)
	$(MAKE) -C $(LIBFT);
	$(CC) -o $@ $^ $(LIBFLAGS) $(FSANITIZE)
	@echo "$(GREEN)Server bonus\n$(RESET_COLOR)"


clean:
	clear;
	rm -rf $(OBJ_F)
	@echo "$(YELLOW)\n☓  CLEAN MINITALK$(RESET_COLOR)"
	cd $(LIBFT) && make fclean; 
	
fclean: clean
	rm -f  $(BIN_C) $(BIN_S) $(BIN_C_BONUS) $(BIN_S_BONUS)
	@echo "$(YELLOW)☓☓ FCLEAN MINITALK\n$(RESET_COLOR)"

re: fclean all


.PHONY: all clean fclean re bonus