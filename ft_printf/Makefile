SRC = ./ft_printf.c ./c.c ./i.c ./s.c ./p.c ./u.c ./x.c
HEADER = ./ft_printf.h
NAME = libftprintf.a
OBJS = $(SRC:.c=.o)
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
