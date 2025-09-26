/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:31:09 by mbenchah          #+#    #+#             */
/*   Updated: 2025/09/26 18:51:20 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_texture	open_texture(t_data *data, char *text)
{
	t_texture	tex;

	if (ft_strncmp (text + ft_strlen(text) - 4, ".xpm", 4))
	{
		ft_destroy_img_texture(data, get_value1(),
			"Texture file must be in .xpm format\n");
	}
	tex.img = mlx_xpm_file_to_image(data->img.mlx,
			text, &tex.width, &tex.height);
	if (!tex.img)
	{
		ft_destroy_img_texture(data, get_value1(), "Failed to load texture\n");
	}
	tex.addr = mlx_get_data_addr(tex.img, &tex.bits_per_pixel,
			&tex.line_length, &tex.endian);
	return (tex);
}

void	ft_destroy_img_texture(t_data *data, int *tab, char *msg)
{
	int	i;

	i = 0;
	while (i < 4 && tab[i] == 1)
	{
		mlx_destroy_image(data->img.mlx, data->tex[i].img);
		i++;
	}
	mlx_destroy_image(data->img.mlx, data->img.img);
	mlx_destroy_window(data->img.mlx, data->img.win);
	if (ft_strlen(msg) > 1)
		ft_error(msg);
	ft_exit(0);
}

int	*get_value1(void)
{
	static int	values[4];

	return (values);
}

void	ft_init_textures(t_data *data)
{
	data->tex[NORTH] = open_texture(data, data->config.north_texture);
	get_value1()[0] = 1;
	data->tex[SOUTH] = open_texture(data, data->config.south_texture);
	get_value1()[1] = 1;
	data->tex[EAST] = open_texture(data, data->config.west_texture);
	get_value1()[2] = 1;
	data->tex[WEST] = open_texture(data, data->config.east_texture);
	get_value1()[3] = 1;
	data->key_board = -1;
	data->key_board2 = -1;
}
