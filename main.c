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

int key_hook(int keycode, t_data *data)
{
    // Camera plane

    if (keycode == UP)
    {
        if (data->map[(int)(data->player.y)][(int)(data->player.x + data->p_dir.x * MOVE_SPEED)] == '0')
            data->player.x += data->p_dir.x * MOVE_SPEED;
        if (data->map[(int)(data->player.y + data->p_dir.y * MOVE_SPEED)][(int)(data->player.x)] == '0')
            data->player.y += data->p_dir.y * MOVE_SPEED;
    }
    if (keycode == DOWN)
    {
        if (data->map[(int)(data->player.y)][(int)(data->player.x - data->p_dir.x * MOVE_SPEED)] == '0')
            data->player.x -= data->p_dir.x * MOVE_SPEED;
        if (data->map[(int)(data->player.y - data->p_dir.y * MOVE_SPEED)][(int)(data->player.x)] == '0')
            data->player.y -= data->p_dir.y * MOVE_SPEED;
    }
    if (keycode == LEFT)
    {
        double old_dir_x = data->p_dir.x;
        data->p_dir.x = data->p_dir.x * cos(-ROT_SPEED) - data->p_dir.y * sin(-ROT_SPEED);
        data->p_dir.y = old_dir_x * sin(-ROT_SPEED) + data->p_dir.y * cos(-ROT_SPEED);
        double old_plane_x = data->plane.x;
        data->plane.x = data->plane.x * cos(-ROT_SPEED) - data->plane.y * sin(-ROT_SPEED);
        data->plane.y = old_plane_x * sin(-ROT_SPEED) + data->plane.y * cos(-ROT_SPEED);
    }
    if (keycode == RIGHT)
    {
        double old_dir_x = data->p_dir.x;
        data->p_dir.x = data->p_dir.x * cos(ROT_SPEED) - data->p_dir.y * sin(ROT_SPEED);
        data->p_dir.y = old_dir_x * sin(ROT_SPEED) + data->p_dir.y * cos(ROT_SPEED);
    }
    printf("Player p_dir: (%f, %f)\n", data->p_dir.x, data->p_dir.y);
    printf("Player plane: (%f, %f)\n", data->plane.x, data->plane.y);
    printf("Player position: (%f, %f)\n", data->player.x, data->player.y);
    mlx_clear_window(data->img.mlx, data->img.win);
    render(data);
    return (0);
}


    

int main(int argc, char **argv)
{
    t_data  data = {0};
    (void) argc;
    (void) argv;

	data.img.mlx = mlx_init();
	data.img.win = mlx_new_window(data.img.mlx, WIDTH, HEIGHT, "Cube_fucking_3D!");
    data.img.img = mlx_new_image(data.img.mlx, WIDTH, HEIGHT);
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length,
								&data.img.endian);
                    
    data.player = (t_coord){1.5, 1.5}; // Player position
    data.p_dir = (t_coord){-1, 0}; // Player direction vector
    data.plane = (t_coord){0, 0.66}; 
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
        "10000000000000000001",
        "10000000000000000001",
        "10000000110000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000001111100000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "11111111111111111111",
        NULL
    };

    data.map = map;
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
    mlx_key_hook(data.img.win, key_hook, &data);
    render(&data);
    // render(&data);
    // mlx_put_image_to_window(data.img.mlx, data.img.win, data.img.img, 0, 0);

	mlx_loop(data.img.mlx);
    return (0);
}