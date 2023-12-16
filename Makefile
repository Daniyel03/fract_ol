NAME 	=	fractol

OBJ	=	$(SRC:.c=.o)

SRC		=	main.c utils.c init.c render.c 

CC	=	gcc

MINILIBX	=	 -lmlx -lX11 -lXext

CFLAGS	=	-Wall -Werror -Wextra

COMP	=	$(CC) $(CFLAGS)

RM		=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(COMP) $(OBJ) -o $(NAME) $(MINILIBX)
clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:			fclean all