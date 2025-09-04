#ifndef CUB_H
#define CUB_H

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

#define WIDTH 1920
#define HEIGHT 1080
#define COTE 64


#define BLUE 0x0000FF
#define GREEN 0x00FFA0

# define TITLE "cub3D"


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
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05


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

typedef struct	s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		_x;
}				t_texture;

typedef struct	s_data {

	t_mlx		img;
	t_coord		player;
	t_coord		p_dir;
	t_coord		plane;
	t_coord		ray_dir;
	t_coord		delta;
	t_coord		side;
	t_wall		wall;
	t_texture	tex;
	float 		perp_wall;	
	char		**map;
	int 		map_length;
	int 		key_fleche;
	int 		key_board;
	

}				t_data;


void			render(t_data *data);
void	ft_put_texture(t_data *data, int x, int y, int line_height, int start, int tex_x);
void	ft_put_px(t_data *data, int x, int y, int color);


#endif