#ifndef CUB3D_H
#define CUB3D_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <limits.h>
#include <mlx.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define BUFFER_SIZE 32

typedef struct s_vector
{
    float x;
    float y;
} t_vector;

typedef struct s_player {
    t_vector position;
    t_vector direction;
    t_vector plane; // Camera plane for field of view
} t_player;

typedef struct s_img {
    void *img;
    char *addr;
    int bits_per_pixel;
    int size_line;
    int endian;
} t_img;

typedef struct s_config {
    char *north_texture;
    char *south_texture;
    char *east_texture;
    char *west_texture;
    int floor_color;   // RGB color for the floor
    int ceiling_color; // RGB color for the ceiling
} t_config;

typedef struct s_map {
    char **grid;
    int width;
    int height;
} t_map;

typedef struct s_game {
    void *mlx;
    void *window;
    t_img *img;
    t_player player;
    t_config config;
    t_map map;
    int should_close;
} t_game;

size_t  ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
void    *ft_malloc(size_t size);
char    **ft_split(char const *s, char c);
char    *ft_atoa(int n);

#endif