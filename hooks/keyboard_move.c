/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:07:15 by mbenchah          #+#    #+#             */
/*   Updated: 2025/09/23 15:23:43 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	move_forward(t_data *data)
{
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x + data->p_dir.x * 0.1 * 4)] == '0')
	{
		data->player.x += data->p_dir.x * 0.1;
	}
	if (data->map[(int)(data->player.y
			+ data->p_dir.y * 0.1 * 4)]
		[(int)(data->player.x)] == '0')
	{
		data->player.y += data->p_dir.y * 0.1;
	}
}

static void	move_backward(t_data *data)
{
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x - data->p_dir.x * 0.1 * 4)] == '0')
	{
		data->player.x -= data->p_dir.x * 0.1;
	}
	if (data->map[(int)(data->player.y
			- data->p_dir.y * 0.1 * 4)]
		[(int)(data->player.x)] == '0')
	{
		data->player.y -= data->p_dir.y * 0.1;
	}
}

static void	move_right(t_data *data)
{
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x + data->norm.x * 0.1 * 4)] == '0')
	{
		data->player.x += data->norm.x * 0.1;
	}
	if (data->map[(int)(data->player.y
			+ data->norm.y * 0.1 * 4)]
		[(int)(data->player.x)] == '0')
	{
		data->player.y += data->norm.y * 0.1;
	}
}

static void	move_left(t_data *data)
{
	if (data->map[(int)(data->player.y)]
		[(int)(data->player.x - data->norm.x * 0.1 * 4)] == '0')
	{
		data->player.x -= data->norm.x * 0.1;
	}
	if (data->map[(int)(data->player.y
			- data->norm.y * 0.1 * 4)]
		[(int)(data->player.x)] == '0')
	{
		data->player.y -= data->norm.y * 0.1;
	}
}

void	keyboard_move(t_data *data)
{
	if (data->key_board2 == W)
		move_forward(data);
	if (data->key_board2 == S)
		move_backward(data);
	if (data->key_board == D)
		move_right(data);
	if (data->key_board == A)
		move_left(data);
}
