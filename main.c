/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:07:19 by mbenchah          #+#    #+#             */
/*   Updated: 2025/09/19 00:53:12 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_texture	open_texture(void *mlx, char *text)
{
    t_texture tex;
    tex.img = mlx_xpm_file_to_image(mlx, text, &tex.width, &tex.height);
    if (!tex.img)
    {
        ft_error("Failed to load texture\n");
    }
    tex.addr = mlx_get_data_addr(tex.img, &tex.bits_per_pixel,
                                 &tex.line_length, &tex.endian);

    return (tex);
}
void ft_init_mlx(t_data *data)
{
    data->img.mlx = mlx_init();
	data->img.win = mlx_new_window(data->img.mlx, WIDTH, HEIGHT, TITLE);
    data->img.img = mlx_new_image(data->img.mlx, WIDTH, HEIGHT);
    data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);

    data->tex[NORTH] = open_texture(data->img.mlx, data->config.north_texture);
    data->tex[SOUTH] = open_texture(data->img.mlx, data->config.south_texture);
    data->tex[EAST] = open_texture(data->img.mlx, data->config.east_texture);
    data->tex[WEST] = open_texture(data->img.mlx, data->config.west_texture);
    data->key_board = -1;
    data->key_board2 = -1;
    ft_raycasting(data, 0, 0.0);
    mlx_hook(data->img.win, 2, 1L<<0, key_press, data);
    mlx_hook(data->img.win, 3, 1L<<1, key_release, data);
    mlx_loop_hook(data->img.mlx, move_, data);             
    mlx_hook(data->img.win, 6, 0, mouse_move, data);
    mlx_hook(data->img.win, 17, 0, close_window, NULL);
}

int main(int argc, char **argv)
{
    t_data  data = {0};
    if (argc != 2)
    {
        printf("Usage: %s <map_file>\n", argv[0]);
        return (1);
    }
    
    init_data(&data, argv[1]);
    ft_init_mlx(&data);
	mlx_loop(data.img.mlx);
    return (0);
}
