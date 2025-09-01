#include "cube.h"

int main(int argc, char **argv)
{
    t_data  data;

    if (argc != 2)
    {
        printf("Error\nInvalid number of arguments\n");
        return (1);
    }
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
    {
        printf("Error\nInvalid file extension\n");
        return (1);
    }
    data.map = parse_map(argv[1]);
    if (!data.map)
    {
        printf("Error\nFailed to parse map\n");
        return (1);
    }
    if (!validate_map(data.map))
    {
        printf("Error\nInvalid map\n");
        free_map(data.map);
        return (1);
    }
    init_game(&data);
    mlx_loop(data.mlx);
    free_map(data.map);
    return (0);
}