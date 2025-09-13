/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:07:10 by mbenchah          #+#    #+#             */
/*   Updated: 2025/09/12 21:03:27 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
   // each map cell = 10x10 pixels

void	ft_put_px(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length
			+ x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int ft_find_tex_x(t_data *data)
{
	double wall_x;

	if (data->wall == EAST || data->wall == WEST)
		wall_x = data->player.y + data->perp_wall * data->ray_dir.y;
	else
		wall_x = data->player.x + data->perp_wall * data->ray_dir.x;
	wall_x -= floor(wall_x);
	return ((int)(wall_x * (double)data->tex[data->wall].width));
}


void	ft_draw_column(t_data *data, int x, int y)
{
	t_prm	prm;

	prm.line_height = (int)HEIGHT / data->perp_wall;
	prm.start = (HEIGHT >> 1) - (prm.line_height >> 1);
	prm.end = (prm.line_height >> 1) + (HEIGHT >> 1);
	prm.tex_x = ft_find_tex_x(data);
	while (y < HEIGHT)
	{
		if (y < prm.start)
			ft_put_px(data, x, y, data->config.floor_color);
		else if(y <= prm.end)
			ft_put_texture(data, x, y, prm);
		else
			ft_put_px(data, x, y, data->config.ceiling_color);
		y++;
	}
}

void	ft_raycasting(t_data *data, int x, double camera_x)
{
    t_map map_coord;
	t_coord step;

	while (x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1;
		data->ray_dir.x = data->p_dir.x + (data->plane.x * camera_x);
		data->ray_dir.y = data->p_dir.y + (data->plane.y * camera_x);
		map_coord.x = (int)data->player.x;
		map_coord.y = (int)data->player.y;
		ft_get_step(data, &step, map_coord);
		ft_dda(data, step, &map_coord);
		if (data->wall == EAST || data->wall == WEST)
			data->perp_wall = data->side.x;
		else
			data->perp_wall = data->side.y;
		ft_draw_column(data, x, 0);
		x++;
	}
    mlx_put_image_to_window(data->img.mlx, data->img.win, data->img.img, 0, 0);
	// draw_minimap(data);
	// draw_player_on_minimap(data);
	// draw_player_dir(data);
}
