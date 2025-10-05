/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:47:46 by mbenchah          #+#    #+#             */
/*   Updated: 2025/09/20 22:47:46 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <mlx.h>

# define WIDTH 1920
# define HEIGHT 1080
# define TITLE "cub3D"
# define W_S " \t\n\v\f\r"
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define BUFFER_SIZE 32

# define FD 1
# define STATE 0

/* Exit keys */
// # define ESC 53

# define ESC 65307
// # define CLOSE_BUTTON 17

// /* Movement keys (WASD) */
// # define W 13
// # define D 2
// # define S 1
// # define A 0


# define CLOSE_BUTTON 33  
# define W 119   // 'w'
# define A 97    // 'a'
# define S 115   // 's'
# define D 100   // 'd'

/* Arrow keys */
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364


/* Player speed */
# define MOVE_SPEED 0.1
# define ROT 0.05

typedef struct s_garbage_collector
{
	char						*ptr;
	struct s_garbage_collector	*next;
}	t_gc;

typedef enum e_wall
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_wall;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_map
{
	int	x;
	int	y;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_config
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		floor_color;
	int		ceiling_color;
}	t_config;

typedef struct s_data
{
	t_mlx		img;
	t_coord		player;
	t_coord		p_dir;
	t_coord		normal;
	t_coord		ray_dir;
	t_coord		delta;
	t_coord		side;
	t_config	config;
	t_wall		wall;
	t_texture	tex[4];
	float		perp_wall;
	char		**map;
	int			key_fleche;
	int			key_board;
	int			key_board2;
}	t_data;

typedef struct s_prm
{
	int	line_height;
	int	start;
	int	end;
	int	tex_x;
}	t_prm;

typedef struct s_mock_map
{
	char				*line;
	struct s_mock_map	*next;
}	t_mock_map;

size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);
char		**ft_split(char const *s, char c);
int			ft_isin(const char c, const char *charset);
int			ft_atoi(const char *str);
int			is_texture_line(char *line);
void		parse_texture_line(t_data *data, char *line);
int			is_color_line(char *line);
void		parse_color_line(t_data *data, char *line);
void		*ft_malloc(size_t size);
void		ft_exit(int code);
void		ft_error(const char *msg);

void		init_mock_map(t_data *data, char *line, int fd);
void		init_data_map(t_mock_map *head, t_data *data);
void		check_map(char **map);
void		init_data(t_data *data, char *filename);
int			is_space_only(char *line);
int			ft_sum(int *arr, int size);
int			*get_value(void);
char		*ft_scipe_spaces(char *line);
int			ft_white_space(char c);
void		ft_init_player(t_data *data);
void		ft_replace_spaces_in_map(char **map);
int			check_lines_empty(char *line, int fd);
int			ft_isin(const char c, const char *charset);
char		*ft_scipe_empty_spaces_line(char *line, int fd);
int			*get_value1(void);
t_texture	open_texture(t_data *data, char *text);
void		ft_destroy_img_texture(t_data *data, int *tab, char *msg);
void		ft_init_textures(t_data *data);
char		*ft_get_value(char *line, int flag);
void		ft_close_fd(void);
int			*get_fd_state(void);
void		check_color_format(char *line);

void		ft_raycasting(t_data *data, int x, double alpha_x);
void		ft_put_texture(t_data *data, int x, int y, t_prm prm);
void		ft_put_px(t_data *data, int x, int y, int color);
void		keyboard_move(t_data *data);
int			close_window(t_data *data);
int			key_release(int keycode, t_data *data);
int			key_press(int keycode, t_data *data);
int			move_(t_data *data);
int			mouse_move(int x, int y, t_data *data);
void		ft_dda(t_data *data, t_coord step, t_map *map_coord);
void		ft_get_step(t_data *data, t_coord *step, t_map map_coord);

#endif