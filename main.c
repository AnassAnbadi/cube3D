#include "cub3D.h"
void init_mlx(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        ft_exit(EXIT_FAILURE);
    data->window = mlx_new_window(data->mlx, 1920, 1880, "Cub3D");
    if (!data->window)
        ft_exit(EXIT_FAILURE);
    data->img = mlx_new_image(data->mlx, 1920, 1880);
    if (!data->img)
        ft_exit(EXIT_FAILURE);
    data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel,
                                       &data->img->size_line, &data->img->endian);
    if (!data->img->addr)
        ft_exit(EXIT_FAILURE);
    // mlx_key_hook(data->window, key_hook, data);
    // mlx_hook(data->window, 17, 0, close_window, data);
}
int main(int argc, char **argv)
{
    t_data data;
    (void)argc;
    // if (argc != 2)
    // {
    //     fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
    //     return EXIT_FAILURE;
    // }
    // init_mlx(&data);
// printf("hhhhhh1 %s",argv[1]);
    init_data(&data, argv[1]);
    / ft_raycasting(&data, 0, 0.0);
    mlx_hook(data.img.win, 2, 1L<<0, key_press, &data);     // Key press
    mlx_hook(data.img.win, 3, 1L<<1, key_release, &data);   // Key release
    mlx_loop_hook(data.img.mlx, move_, &data);             
    mlx_hook(data.img.win, 6, 0, mouse_move, &data);
    mlx_hook(data.img.win, 17, 0, close_window, NULL);
   
    // render(&data);
    // mlx_put_image_to_window(data.img.mlx, data.img.win, data.img.img, 0, 0);

	mlx_loop(data.img.mlx);


    return EXIT_SUCCESS;
}