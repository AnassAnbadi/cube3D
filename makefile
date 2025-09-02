NAME = cube
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = main.c file2.c
OBJS = $(SRCS:.c=.o)
HEADER = cube.h


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) -Imlx -c $< -o $@   

# $(CFLAGS) 

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all