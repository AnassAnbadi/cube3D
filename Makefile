NAME = cube
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = parseing/check.c \
       parseing/init_data.c \
       utils/ft_.c \
       utils/ft_atoi.c \
       utils/ft_split.c \
       utils/get_next_line.c \
       utils/utils.c \

OBJS = $(SRCS:.c=.o)
HEADER = cub3D.h

# Choose linking line depending on your system
# For Linux with X11:
# LIBS = -lmlx -lXext -lX11 -lm
# For macOS with frameworks:
LIBS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) main.c -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
