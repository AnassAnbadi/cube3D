/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:07:19 by mbenchah          #+#    #+#             */
/*   Updated: 2025/09/24 02:50:29 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_mlx(t_data *data)
{
	data->img.mlx = mlx_init();
	if (!data->img.mlx)
		ft_error("Failed to initialize MLX\n");
	data->img.win = mlx_new_window(data->img.mlx, WIDTH, HEIGHT, TITLE);
	if (!data->img.win)
	{
		// free(data->img.mlx);//////////////////
		ft_error("Failed to create window\n");
	}
	data->img.img = mlx_new_image(data->img.mlx, WIDTH, HEIGHT);
	if (!data->img.img)
	{
		mlx_destroy_window(data->img.mlx, data->img.win);
		// free(data->img.mlx);///////////////////////////////////
		ft_error("Failed to create image\n");
	}
	data->img.addr = mlx_get_data_addr(
			data->img.img,
			&data->img.bits_per_pixel,
			&data->img.line_length,
			&data->img.endian);
}
void f(void){///////////////////////////////
	system("leaks cub3D");
}
int	main(int argc, char **argv)
{
	atexit(f);////////////////////////////////////
	t_data	data;

	data = (t_data){0};
	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	init_data(&data, argv[1]);
	ft_init_mlx(&data);
	ft_init_textures(&data);
	ft_raycasting(&data, 0, 0.0);
	mlx_hook(data.img.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.img.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.img.mlx, move_, &data);
	mlx_hook(data.img.win, 6, 0, mouse_move, &data);
	mlx_hook(data.img.win, 17, 0, close_window, &data);
	// exit(0);
	mlx_loop(data.img.mlx);

	return (0);
}
