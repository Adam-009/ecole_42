
SRC = main.c initialize.c check_map.c utils.c window.c
NAME = so_long
OBJS = $(SRC:.c=.o)
RM = rm -rf

MLX_PATH = ./minilibx-linux
MLX = $(MLX_PATH)/libmlx.a

LIBFT_PATH = ./my_libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(MLX) $(NAME)


$(MLX):
	$(MAKE) -C $(MLX_PATH)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft -lm -lX11 -lXext -g

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -I$(MLX_PATH) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
