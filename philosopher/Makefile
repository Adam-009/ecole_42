SRC = \
	main.c\
	parsing/parsing.c\
	parsing/parsing2.c\
	utils/ft_atoll.c\
	utils/philo_status.c\
	utils/threads_mutex.c\
	struct/list_philo.c\
	struct/list_fork.c\
	struct/rules_struct.c\
	utils.c
NAME = philo
OBJS = $(SRC:.c=.o)
RM = rm -rf

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread #-fsanitize=thread

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re