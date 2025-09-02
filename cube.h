#ifndef CUB_H
#define CUB_H

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

#define WIDTH 1920
#define HEIGHT 1080
#define COTE 64
#define PI 3.14159265358979323846

#define BLUE 0x0000FF
#define GREEN 0x00FFA0

// # define TITLE "cub3D"
// # define HEIGHT 720
// # define WIDTH 1280

/* Exit keys */
# define ESC 53
# define CLOSE_BUTTON 17   // DestroyNotify (same as Linux)

/* Movement keys (WASD) */
# define W 13
# define D 2
# define S 1
# define A 0

/* Arrow keys */
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

/* Player speed */
# define MOVE_SPEED 0.5
# define ROT_SPEED 0.1


typedef enum e_wall
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}				t_wall;

typedef struct	s_coord {
	float	x;
	float	y;
}				t_coord;

typedef struct	s_map {
	int		x;
	int 	y;
}				t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct	s_data {

	t_mlx		img;
	t_coord		player;
	t_coord		p_dir;
	t_coord		plane;
	t_coord		ray_dir;
	t_coord		delta;
	t_coord		side;
	t_wall		wall;
	float 		perp_wall;	
	char		**map;
	int 		map_length;
	

}				t_data;


void			render(t_data *data);


#endif