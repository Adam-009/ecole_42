SRC = ./main.c
NAME = ft_display_file
OBJS = $(SRCS:.c=.o)
RM = rm -rf


all : $(NAME)

$(NAME) : $(SRC)
	cc -Wall -Wextra -Werror $(SRC) -o $(NAME)
clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
