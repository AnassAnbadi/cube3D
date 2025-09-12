NAME = cube
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = main.c raycast/ft_raycasting.c raycast/ft_put_texture.c hooks/keyboard_move.c hooks/events.c raycast/ft_dda.c mini_map.c
OBJS = $(SRCS:.c=.o)
HEADER = cube.h


all : $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS)  -Lmlx -lmlx_Linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) -Imlx -c $< -o $@   

# $(CFLAGS) //////////////////////////////////////////////

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all