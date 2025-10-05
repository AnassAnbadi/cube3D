/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:07:01 by mbenchah          #+#    #+#             */
/*   Updated: 2025/09/20 21:49:33 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_get_delta(t_data *data)
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

void	ft_get_step(t_data *data, t_coord *step, t_map map_coord)
{
	ft_get_delta(data);
	if (data->ray_dir.x < 0)
	{
		step->x = -1;
		data->side.x = (data->player.x - map_coord.x)
			*data->delta.x;
	}
	else
	{
		step->x = 1;
		data->side.x = (map_coord.x + 1.0 - data->player.x)
			*data->delta.x;
	}
	if (data->ray_dir.y < 0)
	{
		step->y = -1;
		data->side.y = (data->player.y - map_coord.y)
			*data->delta.y;
	}
	else
	{
		step->y = 1;
		data->side.y = (map_coord.y + 1.0 - data->player.y)
			*data->delta.y;
	}
}

void	ft_dda(t_data *data, t_coord step, t_map *map_coord)
{
	while (1)
	{
		if (data->side.x < data->side.y)
		{
			map_coord->x += step.x;
			data->wall = WEST;
			if (step.x > 0)
				data->wall = EAST;
			if (data->map[map_coord->y][map_coord->x] == '1')
				break ;
			data->side.x += data->delta.x;
		}
		else
		{
			map_coord->y += step.y;
			data->wall = NORTH;
			if (step.y > 0)
				data->wall = SOUTH;
			if (data->map[map_coord->y][map_coord->x] == '1')
				break ;
			data->side.y += data->delta.y;
		}
	}
}
