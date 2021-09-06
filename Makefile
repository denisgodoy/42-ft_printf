NAME := libftprintf.a

LIBFT_DIR := libft

LIBFT := $(LIBFT_DIR)/libft.a

CC := clang

CFLAGS := -Wall -Werror -Wextra

SRC := ft_printf.c ft_count_format.c

OBJ := $(SRC:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	rm -f $@$
	ar -rcs $@ $(OBJ) $(LIBFT)

clean:	clean
	$(MAKE) -C $(LIBFT_DIR) $@$
	rm -f ./a.out
	rm -f *.o

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) $@$
	rm -f $(NAME)

re:	fclean all
