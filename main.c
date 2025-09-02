#include "cub3D.h"
void init_mlx(t_game *game, int ac, char **av);
{

}
int main(int argc, char **argv)
{
    t_game game;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (load_map(argv[1], &game) != 0)
    {
        fprintf(stderr, "Error loading map file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Initialize graphics
    if (init_graphics(&game) != 0)
    {
        fprintf(stderr, "Error initializing graphics\n");
        free_map(&game);
        return EXIT_FAILURE;
    }

    // Main game loop
    while (!game.should_close)
    {
        handle_input(&game);
        update_game(&game);
        render_frame(&game);
    }

    // Cleanup
    cleanup_graphics(&game);
    free_map(&game);

    return EXIT_SUCCESS;
}