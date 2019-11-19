
SRC = main.c ft_printf.c ft_printf_utils0.c ft_printf_utils1.c\
	ft_printf_utils2.c ft_printf_utils3.c ft_printf_utils4.c ft_printf_utils5.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wextra -Werror -Wall -g

all :
	@echo "=========================== EXEC ==========================="
	@gcc $(FLAGS) $(SRC)
	@echo "=========================== COMP ==========================="
	@./a.out