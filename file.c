#include "cube.h"


void ft_raycasting(char **map, t_data img)
{
    t_vect pos = {1, 1}; // Player position
    t_vect pdir = {1, 0}; // Player direction vector
    t_vect plane = {0, 0.66}; // Camera plane

    for (int x = 0; x < WIDTH; x++)
    {
        float cameraX = 2 * x / (float)WIDTH - 1; // x-coordinate in camera space
        t_vect rayDir = {pdir.x + plane.x * cameraX, pdir.y + plane.y * cameraX};

        int mapX = (int)pos.x;
        int mapY = (int)pos.y;

        float sideDistX;
        float sideDistY;

        float deltaDistX = (rayDir.x == 0) ? 1e30 : fabs(1 / rayDir.x);
        float deltaDistY = (rayDir.y == 0) ? 1e30 : fabs(1 / rayDir.y);
        float perpWallDist;

        int stepX;
        int stepY;

        int hit = 0; // Was there a wall hit?
        int side; // Was a NS or a EW wall hit?

        // Calculate step and initial sideDist
        if (rayDir.x < 0)
        {
            stepX = -1;
            sideDistX = (pos.x - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - pos.x) * deltaDistX;
        }
        if (rayDir.y < 0)
        {
            stepY = -1;
            sideDistY = (pos.y - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - pos.y) * deltaDistY;
        }

        // Perform DDA
        while (hit == 0)
        {
            // Jump to next map square, OR in x-direction, OR in y-direction
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            // Check if ray has hit a wall
            if (map[mapY][mapX] == '1') hit = 1;
        }

        // Calculate distance projected on camera direction
}
