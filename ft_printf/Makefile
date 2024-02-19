NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		utils/struct.c	utils/clean_reset.c\
		check/ft_format_checker.c \
		print/ft_print_digits.c	\
		print/ft_print_p.c \
		print/ft_print_c.c	print/ft_print_d_i.c \
		print/ft_print_s.c print/ft_print_u_x.c	
OBJS = $(SRCS:.c=.o)

LIBFT_NAME = libft.a
LIBFT_DIR = ./libft


GREEN = \033[0;32m
MAGENTA	= \033[0;35m
RED = \033[0;31m
RESET_COLOR = \033[0m


# bonus:	all

all: $(NAME)

makelibft:
	cd $(LIBFT_DIR); make
	cp $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)

$(NAME): makelibft $(OBJS)
	ar rcs $@ $(OBJS)
	@echo "$(GREEN)Compiled successfully ! 🎉 $(MAGENTA)FT_PRINTF$(RESET_COLOR)"

$(OBJS): $(SRCS)

clean:
	@rm -f $(OBJS)
	cd $(LIBFT_DIR); make clean
	@echo "$(RED)cleaned ft_printf *.o files$(RESET_COLOR)"

fclean: clean
	@rm -f $(NAME)
	cd $(LIBFT_DIR); make fclean
	@echo "$(RED)cleaned libftprintf.a$(RESET_COLOR)"

re: fclean all

.PHONY: all clean fclean re

# make -C $(LIBFT_DIR)
# make -C $(LIBFT_DIR) is and equivalent to: cd $(LIBFT_DIR); make 
# cp - means copy than specify $(src) $(dest)