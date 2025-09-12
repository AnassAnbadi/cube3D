/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:07:19 by mbenchah          #+#    #+#             */
/*   Updated: 2025/09/12 21:14:42 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


// int mouse_move(int x, int y, t_data *data)
// {
//     static int last_x = WIDTH / 2;
//     int delta_x;
//     double angle;
//     double old_dir_x;
//     double old_plane_x;
    
//     if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
//         return (0);
//     delta_x = x - last_x;
//     last_x = x;
//     angle = delta_x * 0.005;
//     data->p_dir.x;
//     data->p_dir.x = data->p_dir.x * cos(angle) - data->p_dir.y * sin(angle);
//     data->p_dir.y = old_dir_x * sin(angle) + data->p_dir.y * cos(angle);
//     old_plane_x = data->plane.x;
//     data->plane.x = data->plane.x * cos(angle) - data->plane.y * sin(angle);
//     data->plane.y = old_plane_x * sin(angle) + data->plane.y * cos(angle);
//     render(data, 0, 0.0);
//     return (0);
// }

// void keyboard_move(t_data *data)
// {
//     if (data->key_board2 == W)
//     {	floa	floatt
//         if (data->map[(int)(data->player.y)][(int)(data->player.x + data->p_dir.x * MOVE_SPEED*4)] == '0')
//             data->player.x += data->p_dir.x * MOVE_SPEED;
//         if (data->map[(int)(data->player.y + data->p_dir.y * MOVE_SPEED*4)][(int)(data->player.x)] == '0')
//             data->player.y += data->p_dir.y * MOVE_SPEED;
//     }
//     if (data->key_board2 == S)
//     {
//         if (data->map[(int)(data->player.y)][(int)(data->player.x - data->p_dir.x * MOVE_SPEED*4)] == '0')
//             data->player.x -= data->p_dir.x * MOVE_SPEED;
//         if (data->map[(int)(data->player.y - data->p_dir.y * MOVE_SPEED*4)][(int)(data->player.x)] == '0')
//             data->player.y -= data->p_dir.y * MOVE_SPEED;
//     }
//     if (data->key_board == D)
//     {
//         if (data->map[(int)(data->player.y)][(int)(data->player.x + data->plane.x * MOVE_SPEED * 4)] == '0')
//             data->player.x += data->plane.x * MOVE_SPEED;
//         if (data->map[(int)(data->player.y + data->plane.y * MOVE_SPEED *4)][(int)(data->player.x)] == '0')
//             data->player.y += data->plane.y * MOVE_SPEED;
//     }
//     if (data->key_board == A)
//     {
//         if (data->map[(int)(data->player.y)][(int)(data->player.x - data->plane.x * MOVE_SPEED*4)] == '0')
//             data->player.x -= data->plane.x * MOVE_SPEED;
//         if (data->map[(int)(data->player.y - data->plane.y * MOVE_SPEED*4)][(int)(data->player.x)] == '0')
//             data->player.y -= data->plane.y * MOVE_SPEED;
//     }
// }





// int move_(t_data *data)
// {
//     double old_dir_x;
//     double old_plane_x;

//     old_dir_x = data->p_dir.x;
//     old_plane_x = data->plane.x;
//     if (data->key_fleche == LEFT)
//     {
//         data->p_dir.x = data->p_dir.x * cos(ROT) + data->p_dir.y * sin(ROT);
//         data->p_dir.y = -old_dir_x * sin(ROT) + data->p_dir.y * cos(ROT);
//         data->plane.x = data->plane.x * cos(ROT) + data->plane.y * sin(ROT);
//         data->plane.y = -old_plane_x * sin(ROT) + data->plane.y * cos(ROT);
//     }
//     if (data->key_fleche == RIGHT)
//     {
//         data->p_dir.x = data->p_dir.x * cos(ROT) - data->p_dir.y * sin(ROT);
//         data->p_dir.y = old_dir_x * sin(ROT) + data->p_dir.y * cos(ROT);
//         data->plane.x = data->plane.x * cos(ROT) - data->plane.y * sin(ROT);
//         data->plane.y = old_plane_x * sin(ROT) + data->plane.y * cos(ROT);
//     }
//     keyboard_move(data);
//     if(data->key_fleche != 0 || data->key_board != -1 || data->key_board2 != -1)
//         render(data, 0, 0.0);
//     return (0);
// }

// int key_press(int keycode, t_data *data)
// {
//     if (keycode == ESC ) // Escape key
//         exit(0);//////////////////////////////////////////////////
//     if (keycode == LEFT || keycode == RIGHT)
//         data->key_fleche = keycode;
//     if (keycode == A || keycode == D)
//         data->key_board = keycode;
//     if (keycode == W || keycode == S)
//         data->key_board2 = keycode;
//     return (0);
// }

// int key_release(int keycode, t_data *data)
// {
//     if (keycode == LEFT || keycode == RIGHT)
//         data->key_fleche = 0;
//     if (keycode == A || keycode == D)
//         data->key_board = -1;
//     if (keycode == W || keycode == S)
//         data->key_board2 = -1;
//     return (0);
// }

// int close_window(void *param)
// {
//     (void)param;
//     exit(0);
//     return (0);
// }
t_texture	open_texture(void *mlx, char *text)
{
    t_texture tex;

    tex.img = mlx_xpm_file_to_image(mlx, text, &tex.width, &tex.height);
    if (!tex.img)
    {
        printf("Error: failed to load tex2 \n");
        exit(1);
    }
    tex.addr = mlx_get_data_addr(tex.img, &tex.bits_per_pixel,
                                 &tex.line_length, &tex.endian);

    return (tex);
}
int main(int argc, char **argv)
{
    t_data  data = {0};
    (void) argc;
    init_data(&data, argv[1]);
	data.img.mlx = mlx_init();
	data.img.win = mlx_new_window(data.img.mlx, WIDTH, HEIGHT, TITLE);
    data.img.img = mlx_new_image(data.img.mlx, WIDTH, HEIGHT);
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);

    data.tex[NORTH] = open_texture(data.img.mlx, "./texture/nass_elghiwane.xpm");
    data.tex[SOUTH] = open_texture(data.img.mlx, "./texture/nass_elghiwane.xpm");
    data.tex[EAST] = open_texture(data.img.mlx, "./texture/pink_floyd.xpm");
    data.tex[WEST] = open_texture(data.img.mlx, "./texture/james.xpm");
                    
    data.player = (t_coord){14.5, 1.5}; // Player position
    data.p_dir = (t_coord){1, 0}; // Player direction vector
    data.plane = (t_coord){0, 0.66};
    data.key_board = -1;
    data.key_board2 = -1;
    
    ft_raycasting(&data, 0, 0.0);
    mlx_hook(data.img.win, 2, 1L<<0, key_press, &data);     // Key press
    mlx_hook(data.img.win, 3, 1L<<1, key_release, &data);   // Key release
    mlx_loop_hook(data.img.mlx, move_, &data);             
    mlx_hook(data.img.win, 6, 0, mouse_move, &data);
    mlx_hook(data.img.win, 17, 0, close_window, NULL);
   
    // render(&data);
    // mlx_put_image_to_window(data.img.mlx, data.img.win, data.img.img, 0, 0);

	mlx_loop(data.img.mlx);
    return (0);
}
