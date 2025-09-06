#include "cube.h"

void	ft_put_px(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


static void	init_delta(t_data *data)
{
	if (data->ray_dir.x == 0)
		data->delta.x = 1e30;
	else
		data->delta.x = fabs(1 / data->ray_dir.x);
	if (data->ray_dir.y == 0)
		data->delta.y = 1e30;
	else
		data->delta.y = fabs(1 / data->ray_dir.y);
}

static void	init_step(t_data *data, t_coord *step, t_map *map_coord)
{
	if (data->ray_dir.x < 0)
	{
		step->x = -1;
		data->side.x = (data->player.x - map_coord->x)
			*data->delta.x;
	}
	else
	{
		step->x = 1;
		data->side.x = (map_coord->x + 1.0 - data->player.x)
			*data->delta.x;
	}
	if (data->ray_dir.y < 0)
	{
		step->y = -1;
		data->side.y = (data->player.y - map_coord->y)
			*data->delta.y;
	}
	else
	{
		step->y = 1;
		data->side.y = (map_coord->y + 1.0 - data->player.y)
			*data->delta.y;
	}
}
// int ft_strlen(const char *s)
// {
// 	int len = 0;
// 	while (s[len] != '\0')
// 		len++;
// 	return len;
// }
// static int	is_out_of_bound(t_data *data, t_map *map_coord)
// {
// 	if (map_coord->y < 0 || map_coord->y >= data->map_length)
// 		return (1);
// 	if (map_coord->x < 0
// 		|| map_coord->x >= ft_strlen(data->map[map_coord->y]))
// 		return (1);
// 	return (0);
// }

static void	dda(t_data *data, t_coord *step, t_map *map_coord)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (data->side.x < data->side.y)
		{
			data->side.x += data->delta.x;
			map_coord->x += step->x;
			if (step->x > 0)
				data->wall = EAST;
			else
				data->wall = WEST;
		}
		else
		{
			data->side.y += data->delta.y;
			map_coord->y += step->y;
			if (step->y > 0)
				data->wall = SOUTH;
			else
				data->wall = NORTH;
		}
		if (data->map[map_coord->y][map_coord->x] == '1') //is_out_of_bound(data) || 
			hit = 1;
	}
}

int ft_find_tex_x(t_data *data)
{
	double wall_x;
	double tex_x;

	if (data->wall == EAST || data->wall == WEST)
		wall_x = data->player.y + data->perp_wall * data->ray_dir.y;
	else
		wall_x = data->player.x + data->perp_wall * data->ray_dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)data->tex.width);
	if ((data->wall == EAST || data->wall == WEST) && data->ray_dir.x > 0)
		tex_x = data->tex.width - tex_x - 1;
	if ((data->wall == NORTH || data->wall == SOUTH) && data->ray_dir.y < 0)
		tex_x = data->tex.width - tex_x - 1;
	return ((int)tex_x);
}

void	draw_line(t_data *data, int x, int y)
{
	t_prm prm;


	prm.line_height = (int)HEIGHT / data->perp_wall;
	prm.start = (HEIGHT >> 1) - (prm.line_height >> 1);
	prm.end = (prm.line_height >> 1) + (HEIGHT >> 1);
	prm.tex_x = ft_find_tex_x(data);
	while (y < prm.start)
		ft_put_px(data, x, y++, BLUE);
	while (y <= prm.end)
		ft_put_texture(data, x, y++, prm); // line_height, start, tex_x
	while (y < HEIGHT)
		ft_put_px(data, x, y++, GREEN);
}

void	ft_raycasting(t_data *data, int x, double camera_x)
{
    t_map map_coord;
	t_coord step;

	step = (t_coord){0};
	map_coord = (t_map){0};
	while (x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1;
		data->ray_dir.x = data->p_dir.x + (data->plane.x * camera_x);
		data->ray_dir.y = data->p_dir.y + (data->plane.y * camera_x);
		map_coord.x = (int)data->player.x;
		map_coord.y = (int)data->player.y;
		init_delta(data);
		init_step(data, &step, &map_coord);
		dda(data, &step, &map_coord);
		if (data->wall == EAST || data->wall == WEST)
			data->perp_wall = (data->side.x - data->delta.x);
		else
			data->perp_wall = (data->side.y - data->delta.y);
		draw_line(data, x, 0);
		x++;
	}
    mlx_put_image_to_window(data->img.mlx, data->img.win, data->img.img, 0, 0);
}
