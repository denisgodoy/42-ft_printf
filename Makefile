NAME := libftprintf.a

LIBFT_DIR := ./42-libft

LIBFT := $(LIBFT_DIR)/libft.a

CC := clang

CFLAGS := -Wall -Werror -Wextra

SRC := ft_printf.c

OBJ := $(SRC:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIBFT_DIR) all
	rm -f $@$
	ar -rcs $@ $(OBJ) $(LIBFT)

clean:	clean
	make -C $(LIBFT_DIR) clean
	rm -rf ./a.out
	rm -rf *.o

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re:	fclean all
