#ifndef CUB_H
#define CUB_H

#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include <math.h>

#define WIDTH 1080
#define HEIGHT 480
#define COTE 64

// 
#define BLUE 0x0000FF
#define GREEN 0x00FFA0

# define TITLE "cub3D"


// /* Exit keys */
// # define ESC 53
// # define CLOSE_BUTTON 17   // DestroyNotify (same as Linux)

// /* Movement keys (WASD) */
// # define W 13
// # define D 2
// # define S 1
// # define A 0

// /* Arrow keys */
// # define UP 126
// # define DOWN 125
// # define LEFT 123
// # define RIGHT 124


# define ESC 65307

# define CLOSE_BUTTON 17   // DestroyNotify

/* Movement keys (WASD) */
# define W 119
# define D 100
# define S 115
# define A 97

/* Arrow keys */
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363


/* Player speed */
# define MOVE_SPEED 0.1
# define ROT 0.05


typedef enum e_wall
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}				t_wall;

typedef struct	s_coord {
	double	x;
	double	y;
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
	t_texture	tex[4];
	float 		perp_wall;	
	char		**map;
	// int 		map_length;
	int 		key_fleche;
	int 		key_board;
	int			key_board2;
	

}				t_data;

typedef struct	s_prm {
	int	line_height;
	int	start;
	int	end;
	int tex_x;
}				t_prm;

void			ft_raycasting(t_data *data, int x, double camera_x);
void			ft_put_texture(t_data *data, int x, int y, t_prm prm);
void			ft_put_px(t_data *data, int x, int y, int color);
void			keyboard_move(t_data *data);
int 			close_window(void *param);
int 			key_release(int keycode, t_data *data);
int 			key_press(int keycode, t_data *data);
int 			move_(t_data *data);
int 			mouse_move(int x, int y, t_data *data);
void			ft_dda(t_data *data, t_coord step, t_map *map_coord);
void			ft_get_step(t_data *data, t_coord *step, t_map map_coord);

#define TILE_SIZE 10

void 			draw_minimap(t_data *data);
void 			draw_player_on_minimap(t_data *data);
void 			draw_player_dir(t_data *data);


#endif