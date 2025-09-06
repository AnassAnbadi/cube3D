#include "cube.h"
#include <string.h>

// void	ft_put_px(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void print_map(t_data img, int x, int y, int color, char **map)
// {
//     unsigned long i = 0;
//     unsigned long j = 0;
//     while (i < 1920/strlen(map[0]))
//     {
//         j = 0;
//         while (j < 1920/strlen(map[0]))
//         {
//             ft_put_px(&img, x + i, y + j, color);
//             j++;
//         }
//         i++;
//     }
// }




int mouse_move(int x, int y, t_data *data)
{
    static int last_x = WIDTH / 2;
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return (0);
    int delta_x = x - last_x;
    last_x = x;
    double angle = delta_x * 0.005;
    double old_dir_x = data->p_dir.x;
    data->p_dir.x = data->p_dir.x * cos(angle) - data->p_dir.y * sin(angle);
    data->p_dir.y = old_dir_x * sin(angle) + data->p_dir.y * cos(angle);
    double old_plane_x = data->plane.x;
    data->plane.x = data->plane.x * cos(angle) - data->plane.y * sin(angle);
    data->plane.y = old_plane_x * sin(angle) + data->plane.y * cos(angle);
    render(data, 0, 0.0);

    return (0);
}

int move_( t_data *data)
{
    if (data->key_fleche == LEFT)
    {
        double old_dir_x = data->p_dir.x;
        data->p_dir.x = data->p_dir.x * cos(ROT_SPEED) + data->p_dir.y * sin(ROT_SPEED);
        data->p_dir.y = -old_dir_x * sin(ROT_SPEED) + data->p_dir.y * cos(ROT_SPEED);
        double old_plane_x = data->plane.x;
        data->plane.x = data->plane.x * cos(ROT_SPEED) + data->plane.y * sin(ROT_SPEED);
        data->plane.y = -old_plane_x * sin(ROT_SPEED) + data->plane.y * cos(ROT_SPEED);
    }
    if (data->key_fleche == RIGHT)
    {
        double old_dir_x = data->p_dir.x;
        data->p_dir.x = data->p_dir.x * cos(ROT_SPEED) - data->p_dir.y * sin(ROT_SPEED);
        data->p_dir.y = old_dir_x * sin(ROT_SPEED) + data->p_dir.y * cos(ROT_SPEED);
        double old_plane_x = data->plane.x;
        data->plane.x = data->plane.x * cos(ROT_SPEED) - data->plane.y * sin(ROT_SPEED);
        data->plane.y = old_plane_x * sin(ROT_SPEED) + data->plane.y * cos(ROT_SPEED);
    }

    if (data->key_board2 == W)
    {
        if (data->map[(int)(data->player.y)][(int)(data->player.x + data->p_dir.x * MOVE_SPEED*4)] == '0')
            data->player.x += data->p_dir.x * MOVE_SPEED;
        if (data->map[(int)(data->player.y + data->p_dir.y * MOVE_SPEED*4)][(int)(data->player.x)] == '0')
            data->player.y += data->p_dir.y * MOVE_SPEED;
    }
    if (data->key_board2 == S)
    {
        if (data->map[(int)(data->player.y)][(int)(data->player.x - data->p_dir.x * MOVE_SPEED*4)] == '0')
            data->player.x -= data->p_dir.x * MOVE_SPEED;
        if (data->map[(int)(data->player.y - data->p_dir.y * MOVE_SPEED*4)][(int)(data->player.x)] == '0')
            data->player.y -= data->p_dir.y * MOVE_SPEED;
    }
    if (data->key_board == D)
    {
        if (data->map[(int)(data->player.y)][(int)(data->player.x + data->plane.x * MOVE_SPEED * 4)] == '0')
            data->player.x += data->plane.x * MOVE_SPEED;
        if (data->map[(int)(data->player.y + data->plane.y * MOVE_SPEED *4)][(int)(data->player.x)] == '0')
            data->player.y += data->plane.y * MOVE_SPEED;
    }
    if (data->key_board == A)
    {
       if (data->map[(int)(data->player.y)][(int)(data->player.x - data->plane.x * MOVE_SPEED*4)] == '0')
            data->player.x -= data->plane.x * MOVE_SPEED;
        if (data->map[(int)(data->player.y - data->plane.y * MOVE_SPEED*4)][(int)(data->player.x)] == '0')
            data->player.y -= data->plane.y * MOVE_SPEED;
    }
    if(data->key_fleche != 0 || data->key_board != -1 || data->key_board2 != -1)
        render(data, 0, 0.0);
    return (0);
}

int key_press(int keycode, t_data *data)
{
    if (keycode == ESC ) // Escape key
        exit(0);//////////////////////////////////////////////////
    if (keycode == LEFT || keycode == RIGHT)
        data->key_fleche = keycode;
    if (keycode == A || keycode == D)
        data->key_board = keycode;
    if (keycode == W || keycode == S)
        data->key_board2 = keycode;
    return (0);
}

int key_release(int keycode, t_data *data)
{
    if (keycode == LEFT || keycode == RIGHT)
        data->key_fleche = 0;
    if (keycode == A || keycode == D)
        data->key_board = -1;
    if (keycode == W || keycode == S)
        data->key_board2 = -1;
    return (0);
}

int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int main(int argc, char **argv)
{
    t_data  data = {0};
    (void) argc;
    (void) argv;

	data.img.mlx = mlx_init();
	data.img.win = mlx_new_window(data.img.mlx, WIDTH, HEIGHT, TITLE);
    data.img.img = mlx_new_image(data.img.mlx, WIDTH, HEIGHT);
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);

    data.tex.img = mlx_xpm_file_to_image(data.img.mlx, "./texture.xpm", &data.tex.width, &data.tex.height);
    if (!data.tex.img)
    {
        printf("Error: failed to load tex2 \n");
        exit(1);
    }
    data.tex.addr = mlx_get_data_addr(data.tex.img, &data.tex.bits_per_pixel,
                                 &data.tex.line_length, &data.tex.endian);

                    
    data.player = (t_coord){1.5, 1.5}; // Player position
    data.p_dir = (t_coord){1, 0}; // Player direction vector
    data.plane = (t_coord){0, 0.66};
    data.key_board = -1;
    data.key_board2 = -1;
    char *map[] = {
        "11111111111111111111",
        "10000000000000000001",
        "10111101111111111001",
        "10100001000000001001",
        "10101111011111101001",
        "10100000010000101001",
        "10111111011110101001",
        "10000001000000100001",
        "11111011111110111111",
        "10000010000010000001",
        "10111110111011111001",
        "10100000100000001001",
        "10101111101111101001",
        "10100000000000100001",
        "10111111111111111001",
        "10000000000000000001",
        "11111111111111111111",
        NULL
    };

    char *map2[] = {
        "111111",
        "100001",
        "100001",
        "100001",
        "111111",
        NULL
    };

    char *map3[] = {
        "11111111111111111111",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000010000000001",
        "10000000010000000001",
        "10000000110000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000001111100000001",
        "10000000000000000001",
        "10000000000000000001",
        "100000000000000000011111111111111",
        "100000000000000000000000000000001",
        "100000000000000000011111111111101",
        "100000000000000000000000000000001",
        "111111111111111111111111111111111",
        NULL
    };

    data.map = map3;
    while(data.map[data.map_length])
        data.map_length++;

    // ft_raycasting(map, &img);
    // while(map[y])
    // {
    //     x = 0;
    //     while(map[y][x])
    //     {
    //         if (map[y][x] == '1')
    //             print_map(img, x * (1920/strlen(map[0])), y * 1920/strlen(map[0]), 0x00FFFFFF, map);
    //         else if (map[y][x] == '0')
    //             print_map(img, x * 1920/strlen(map[0]), y * 1920/strlen(map[0]), 0x00000000, map);
    //         // else if (map[y][x] == 'P')
    //         //     print_map(img, x * 100, y * 100, 0x0000FF00);
    //         x++;
    //     }
    //     y++;
    // }

    // mlx_hook(data.win, 2, 1L<<0, key_press, &data);
    // mlx_hook(data.win, 3, 1L<<1, key_release, &data);

    // mlx_key_hook(data.img.win, key_hook, &data);
    render(&data, 0, 0.0);
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
