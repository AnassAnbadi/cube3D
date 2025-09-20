/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:06:55 by mbenchah          #+#    #+#             */
/*   Updated: 2025/09/20 22:29:58 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	mouse_move(int x, int y, t_data *data)
{
	static int	last_x = WIDTH / 2;
	int			delta_x;
	double		angle;
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = data->p_dir.x;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	delta_x = x - last_x;
	last_x = x;
	angle = delta_x * 0.005;
	data->p_dir.x = data->p_dir.x * cos(angle) - data->p_dir.y * sin(angle);
	data->p_dir.y = old_dir_x * sin(angle) + data->p_dir.y * cos(angle);
	old_plane_x = data->plane.x;
	data->plane.x = data->plane.x * cos(angle) - data->plane.y * sin(angle);
	data->plane.y = old_plane_x * sin(angle) + data->plane.y * cos(angle);
	ft_raycasting(data, 0, 0.0);
	return (0);
}

int	move_(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->p_dir.x;
	old_plane_x = data->plane.x;
	if (data->key_fleche == LEFT)
	{
		data->p_dir.x = data->p_dir.x * cos(ROT) + data->p_dir.y * sin(ROT);
		data->p_dir.y = -old_dir_x * sin(ROT) + data->p_dir.y * cos(ROT);
		data->plane.x = data->plane.x * cos(ROT) + data->plane.y * sin(ROT);
		data->plane.y = -old_plane_x * sin(ROT) + data->plane.y * cos(ROT);
	}
	if (data->key_fleche == RIGHT)
	{
		data->p_dir.x = data->p_dir.x * cos(ROT) - data->p_dir.y * sin(ROT);
		data->p_dir.y = old_dir_x * sin(ROT) + data->p_dir.y * cos(ROT);
		data->plane.x = data->plane.x * cos(ROT) - data->plane.y * sin(ROT);
		data->plane.y = old_plane_x * sin(ROT) + data->plane.y * cos(ROT);
	}
	keyboard_move(data);
	if (data->key_fleche || data->key_board != -1 || data->key_board2 != -1)
		ft_raycasting(data, 0, 0.0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_destroy_img_texture(data, get_value1(), "E");
	if (keycode == LEFT || keycode == RIGHT)
		data->key_fleche = keycode;
	if (keycode == A || keycode == D)
		data->key_board = keycode;
	if (keycode == W || keycode == S)
		data->key_board2 = keycode;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == LEFT || keycode == RIGHT)
		data->key_fleche = 0;
	if (keycode == A || keycode == D)
		data->key_board = -1;
	if (keycode == W || keycode == S)
		data->key_board2 = -1;
	return (0);
}

int	close_window(t_data *data)
{
	ft_destroy_img_texture(data, get_value1(), "E");
	return (0);
}
