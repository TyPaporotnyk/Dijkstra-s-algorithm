RM	=	rm -f

SRC	=	src/main.c \

OBJS	=	$(SRC:.c=.o)

NAME	=	Dijkstra-s-algorithm

all: $(OBJS)
	gcc $(OBJS) -l csfml-graphics -l csfml-audio -o $(NAME) -g3

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all