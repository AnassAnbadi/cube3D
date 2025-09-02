#ifndef CUB3D_H
#define CUB3D_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <mlx.h>

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
#endif