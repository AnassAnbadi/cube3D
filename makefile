CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = main.c
OBJS = $(SRCS:.c=.o)
HEADER = cube.h
NAME = cube

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@


clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all