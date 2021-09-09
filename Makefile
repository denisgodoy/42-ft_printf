NAME := libftprintf.a

LIBFT_DIR := libft

LIBFT := $(LIBFT_DIR)/libft.a

CC := clang

CFLAGS := -Wall -Werror -Wextra

SRC := ft_printf.c ft_strrev.c ft_count_decimal_u.c ft_utoa.c ft_utoa_hex.c

OBJ := $(SRC:%.c=%.o)

LIBFT_OBJ := $(LIBFT_DIR)/*.o

SRC_OBJ := $(OBJ) $(LIBFT) $(LIBFT_OBJ)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C $(LIBFT_DIR) all
	rm -f $(NAME)
	ar -rcs $(NAME) $(SRC_OBJ)

clean:	clean
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f ./a.out
	rm -f *.o

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:	fclean all

t:
	$(CC) $(CFLAGS) ft_printf.c $(NAME)
	./a.out
