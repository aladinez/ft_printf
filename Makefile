NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils0.c ft_printf_utils1.c\
	ft_printf_utils2.c ft_printf_utils3.c ft_printf_utils4.c ft_printf_utils5.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wextra -Werror -Wall

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	
$(OBJ) :	
	gcc -c $(FLAGS) $(SRC)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

all : $(NAME)

re : fclean all

