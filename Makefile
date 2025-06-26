NAME = libftprintf.a

CC = cc

SRC = ft_printf.c utils.c

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o);

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)
all:$(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
