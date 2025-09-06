#include "cub3D.h"
// void init_mlx(t_game *game)
// {
//     game->mlx = mlx_init();
//     if (!game->mlx)
//         ft_exit(EXIT_FAILURE);
//     game->window = mlx_new_window(game->mlx, 1920, 1880, "Cub3D");
//     if (!game->window)
//         ft_exit(EXIT_FAILURE);
//     game->img = mlx_new_image(game->mlx, 1920, 1880);
//     if (!game->img)
//         ft_exit(EXIT_FAILURE);
//     game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel,
//                                        &game->img->size_line, &game->img->endian);
//     if (!game->img->addr)
//         ft_exit(EXIT_FAILURE);
//     // mlx_key_hook(game->window, key_hook, game);
//     // mlx_hook(game->window, 17, 0, close_window, game);
// }
int main(int argc, char **argv)
{
    t_game game;
    (void)argc;
    // if (argc != 2)
    // {
    //     fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
    //     return EXIT_FAILURE;
    // }
    // init_mlx(&game);
    write(1, "error1\n",8);
// printf("hhhhhh1 %s",argv[1]);
    init_data(&game, argv[1]);
    // check_file(&game);
    // init_player(&game);
    // char *filename = "                ";
    // int len = ft_strlen(filename);


    return EXIT_SUCCESS;
}