NAME = cube
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = main.c file2.c texture_getter.c keyboard_move.c events.c
OBJS = $(SRCS:.c=.o)
HEADER = cube.h


all : $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS)  -Lmlx -lmlx_Linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) -Imlx -c $< -o $@   

# $(CFLAGS) 

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all