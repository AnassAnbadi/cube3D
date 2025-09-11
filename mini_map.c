#include "cube.h"

void draw_player_dir(t_data *data)
{
    int px = (int)(data->player.x * TILE_SIZE);
    int py = (int)(data->player.y * TILE_SIZE);

    int dx = (int)(data->p_dir.x * 10);
    int dy = (int)(data->p_dir.y * 10);

    int i = 0;
    while (i < 20) // short line
    {
        ft_put_px(data, px + dx * i / 10,
                        py + dy * i / 10,
                        0xFF0000);
        i++;
    }
}
void draw_player_on_minimap(t_data *data)
{
    int px = (int)(data->player.x * TILE_SIZE);
    int py = (int)(data->player.y * TILE_SIZE);

    int size = 3;
    int y = -size;
    while (y <= size)
    {
        int x = -size;
        while (x <= size)
        {
            ft_put_px(data, px + x, py + y, 0xFF0000); // red player dot
            x++;
        }
        y++;
    }
}
void draw_minimap(t_data *data)
{
    int i = 0;
    while (data->map[i]) // iterate rows (y)
    {
        int j = 0;
        while (data->map[i][j]) // iterate cols (x)
        {
            int color;
            if (data->map[i][j] == '1')
                color = 0x808080; // gray for walls
            else
                color = 0xFFFFFF; // white for empty space

            int y = 0;
            while (y < TILE_SIZE)
            {
                int x = 0;
                while (x < TILE_SIZE)
                {
                    ft_put_px(data, j * TILE_SIZE + x,
                                    i * TILE_SIZE + y,
                                    color);
                    x++;
                }
                y++;
            }
            j++;
        }
        i++;
    }
}
