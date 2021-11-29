NAME := libftprintf.a

LIBFT_DIR := 42-libft

UTILS_DIR := utils

LIBFT := $(LIBFT_DIR)/libft.a

CC := gcc

CFLAGS := -Wall -Werror -Wextra

SRC := ft_printf.c

BONUS_SRC := ft_printf_bonus.c

UTILS_SRC := $(addprefix $(UTILS_DIR)/, ft_format.c ft_format_utils.c ft_stoa_hex.c \
ft_strrev.c ft_utoa_hex.c ft_utoa.c)

UTILS_BONUS_SRC := $(addprefix $(UTILS_DIR)/, ft_format_bonus.c ft_flag_format_bonus.c \
ft_format_utils_bonus.c ft_stoa_hex_bonus.c ft_strrev_bonus.c ft_utoa_hex_bonus.c ft_utoa_bonus.c)

OBJ := $(SRC:%.c=%.o)

BONUS_OBJ := $(BONUS_SRC:%.c=%.o)

UTILS_OBJ := $(UTILS_SRC:%.c=%.o)

UTILS_BONUS_OBJ := $(UTILS_BONUS_SRC:%.c=%.o)

SRC_OBJ := $(OBJ) $(UTILS_OBJ)

BONUS_SRC_OBJ := $(BONUS_OBJ) $(UTILS_BONUS_OBJ)

all:	$(NAME)

bonus:	$(BONUS_SRC_OBJ)
	$(MAKE) -C $(LIBFT_DIR) all
	rm -f $(NAME)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(BONUS_SRC_OBJ)

$(NAME):	$(SRC_OBJ)
	$(MAKE) -C $(LIBFT_DIR) all
	rm -f $(NAME)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(SRC_OBJ)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f ./a.out
	rm -f $(SRC_OBJ) $(BONUS_SRC_OBJ)

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:	fclean all
