NAME = cube
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = main.c file.c
OBJS = main.o
HEADER = cube.h


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all