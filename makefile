NAME = cube
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = main.c raycast/ft_raycasting.c raycast/ft_put_texture.c hooks/keyboard_move.c hooks/events.c raycast/ft_dda.c parseing/check.c \
       parseing/init_data.c \
       utils/ft_.c \
       utils/ft_atoi.c \
       utils/ft_split.c \
       utils/get_next_line.c \
       utils/utils.c

OBJS = $(SRCS:.c=.o)
HEADER = Cub3D.h


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