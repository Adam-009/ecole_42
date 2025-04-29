SRC = ./minishell.c ./utils.c ./check_comm/check_comm.c ./check_comm/check_comm_utils.c ./openfile/openfile.c ./openfile/openfile_utils.c ./commands/pwd.c ./commands/env.c ./commands/echo.c ./commands/cd.c ./commands/exit.c
NAME = minishell
OBJS = $(SRC:.c=.o)
RM = rm -rf

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re