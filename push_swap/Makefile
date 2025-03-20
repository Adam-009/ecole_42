SRC = main.c utils.c check_list/check_list.c check_list/check_if_already_listed.c list.c moves/ss_sa_sb.c ./sort/utils.c ./sort/init_sort2.c ./sort/init_sort.c ./sort/sort.c ./sort/sort2.c moves/pa_pb.c moves/ra_rb_rr.c moves/rra_rrb_rrr.c
NAME = push_swap
OBJS = $(SRC:.c=.o)
RM = rm -rf

LIBFT_PATH = ./my_libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft

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
