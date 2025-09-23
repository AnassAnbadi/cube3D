NAME = cub3D
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = main.c init_texture.c raycast/ft_raycasting.c raycast/ft_put_texture.c hooks/keyboard_move.c hooks/events.c raycast/ft_dda.c parseing/check.c \
       parseing/init_data.c parseing/utils_map.c \
       utils/ft_.c \
       utils/ft_atoi.c \
       utils/ft_split.c \
       utils/get_next_line.c \
       utils/utils.c \
       parseing/init_element.c \
       utils/utils1.c

OBJS = $(SRCS:.c=.o)
HEADER = cub3D.h

all : $(NAME)
bonus : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -fsanitize=address -Lmlx -lmlx_Linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)


%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all