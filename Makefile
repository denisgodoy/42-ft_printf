NAME := libftprintf.a

LIBFT_DIR := libft

LIBFT := $(LIBFT_DIR)/libft.a

CC := clang

CFLAGS := -Wall -Werror -Wextra

SRC := ft_printf.c

OBJ := $(SRC:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	rm -f $(NAME)
	ar -rcs $(NAME) $(OBJ) $(LIBFT)

clean:	clean
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f ./a.out
	rm -f *.o

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:	fclean all
