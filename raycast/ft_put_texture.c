/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:07:06 by mbenchah          #+#    #+#             */
/*   Updated: 2025/09/12 21:03:19 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int get_tex_color(t_texture *tex, int tex_x, int tex_y)
{
	char    *dst;

	dst = tex->addr + (tex_y * tex->line_length + tex_x * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void ft_put_texture(t_data *data, int x, int y, t_prm prm)
{
	int		tex_height;
	double	tex_pos;
	int		tex_y;

	if (y >= HEIGHT)
		return;
	tex_height = data->tex[data->wall].height;
	tex_pos = (double)(y - prm.start) / prm.line_height;	
	tex_y = (int)(tex_pos * tex_height);
	if (tex_y >= tex_height)
		tex_y = tex_height - 1;
	ft_put_px(data, x, y, get_tex_color(&data->tex[data->wall],
		prm.tex_x, tex_y));
}
