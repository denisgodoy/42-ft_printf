NAME := libftprintf.a

LIBFT_DIR := libft

UTILS_DIR := utils

LIBFT := $(LIBFT_DIR)/libft.a

CC := clang

CFLAGS := -Wall -Werror -Wextra

SRC := ft_printf.c

UTILS_SRC := $(addprefix $(UTILS_DIR)/, ft_format_str.c ft_format_utils.c ft_stoa_hex.c \
ft_strrev.c ft_utoa_hex.c ft_utoa.c)

OBJ := $(SRC:%.c=%.o)

UTILS_OBJ := $(UTILS_SRC:%.c=%.o)

SRC_OBJ := $(OBJ) $(UTILS_OBJ)

all:	$(NAME)

$(NAME):	$(SRC_OBJ)
	$(MAKE) -C $(LIBFT_DIR) all
	rm -f $(NAME)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(SRC_OBJ)

clean:	clean
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f ./a.out
	rm -f $(SRC_OBJ)

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:	fclean all
