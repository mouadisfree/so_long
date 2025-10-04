NAME = so_long

SRC = 	ft_itoa.c \
		ft_split.c \
		get_next_line.c \
		invalid_map_extra.c \
		invalid_map.c \
		libft.c \
		main.c \
		positions.c \
		mlx_init.c \
		left.c \
		right.c \
		up.c \
		down.c \
		the_end.c \

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L /usr/include/minilibx-linux/ -lmlx -lXext -lX11

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re