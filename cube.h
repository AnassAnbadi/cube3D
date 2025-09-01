#ifndef CUB_H
#define CUB_H

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

#define HEIGHT 1920
#define WIDTH 1080
#define COTE 64
#define PI 3.14159265358979323846

typedef struct	s_vec {
	float	x;
	float	y;
}				t_vect;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


#endif