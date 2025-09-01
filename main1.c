#include "cube.h"
#include <string.h>

void	ft_put_px(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void print_map(t_data img, int x, int y, int color, char **map)
{
    unsigned long i = 0;
    unsigned long j = 0;
    while (i < 1920/strlen(map[0]))
    {
        j = 0;
        while (j < 1920/strlen(map[0]))
        {
            ft_put_px(&img, x + i, y + j, color);
            j++;
        }
        i++;
    }
}


int main(int argc, char **argv)
{
    t_data  img;
    (void) argc;
    (void) argv;
    void	*mlx;
	void	*mlx_win;
    int x = 0;
    int y = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1920, "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1920);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
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

    while(map[y])
    {
        x = 0;
        while(map[y][x])
        {
            if (map[y][x] == '1')
                print_map(img, x * (1920/strlen(map[0])), y * 1920/strlen(map[0]), 0x00FFFFFF, map);
            else if (map[y][x] == '0')
                print_map(img, x * 1920/strlen(map[0]), y * 1920/strlen(map[0]), 0x00000000, map);
            // else if (map[y][x] == 'P')
            //     print_map(img, x * 100, y * 100, 0x0000FF00);
            x++;
        }
        y++;
    }
                                
    // ft_put_px(&img, 1, 1, 0x00FFFFFF);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);

    // if (argc != 2)
    // {
    //     printf("Error\nInvalid number of arguments\n");
    //     return (1);
    // }
    // if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
    // {
    //     printf("Error\nInvalid file extension\n");
    //     return (1);
    // }
    // data.map = parse_map(argv[1]);
    // char *map[] = 
    // if (!data.map)
    // {
    //     printf("Error\nFailed to parse map\n");
    //     return (1);
    // }
    // if (!validate_map(data.map))
    // {
    //     printf("Error\nInvalid map\n");
    //     free_map(data.map);
    //     return (1);
    // }
    // init_game(&data);
    // mlx_loop(data.mlx);
    // free_map(data.map);
    return (0);
}