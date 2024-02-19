NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

# SRCS = 	ft_calloc.c		ft_isdigit.c	ft_memcmp.c		ft_putchar_fd.c	ft_split.c  \
# 		ft_strjoin.c	ft_strmapi.c	ft_strtrim.c	ft_isalnum.c	ft_toupper.c  \
# 		ft_isprint.c	ft_memcpy.c		ft_putendl_fd.c	ft_strchr.c		ft_strlcat.c  \
# 		ft_strncmp.c	ft_substr.c		ft_atoi.c		ft_isalpha.c	ft_itoa.c  \
# 		ft_putnbr_fd.c	ft_strdup.c		ft_strlcpy.c	ft_strnstr.c	ft_tolower.c  \
# 		ft_bzero.c		ft_isascii.c	ft_memchr.c		ft_memset.c		ft_putstr_fd.c  \
# 		ft_striteri.c	ft_strlen.c		ft_strrchr.c	ft_memmove.c \
# 		ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c ft_lstadd_back.c \
# 		ft_lstdelone.c	ft_lstclear.c		ft_lstiter.c	ft_lstmap.c
SRCS = src/*.c

OBJ_F = obj/
OBJS = $(SRCS:.c=.o)
OBJ_P = $(addprefix $(OBJ_F), $(OBJS))

GREEN = \033[0;32m
MAGENTA	= \033[0;35m
YELLOW = \033[0;33m
RESET_COLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJ_P)
	@ar -rcs $@ $(OBJ_P)
	@echo "$(GREEN)LIBFT COMPILED$(RESET_COLOR)"

$(OBJ_F)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_P)
	@echo "$(YELLOW)CLEAN LIBFT$(RESET_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)FCLEAN LIBFT$(RESET_COLOR)"

re: fclean all

.PHONY: all clean fclean re bonus

#$@ means the command which starts this rool, the target file for it - $(NAME)
#$^ means all the dependencies for that rool - $(OBJ_P)
#$< means to do for each dependency separately, with the corresponing src file

# .PHONY: means that these name of the commands need to be executed even if files with the same names happen to exist in the directory
