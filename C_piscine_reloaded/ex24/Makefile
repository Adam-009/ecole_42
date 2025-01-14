SRC = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
HEADER = ./includes/ft.h
NAME = libft.a
OBJS = $(SRCS:.c=.o)
RM = rm -rf


all : $(NAME)

$(NAME) : $(HEADER) $(OBJS)
	ar rcs $(NAME) $(OBJS) $(HEADER)
clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
