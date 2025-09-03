#include "cub3D.h"

int is_texture_line(line)
{
    return (ft_strncmp(line, "NO ", 3) == 0 ||
            ft_strncmp(line, "SO ", 3) == 0 ||
            ft_strncmp(line, "EA ", 3) == 0 ||
            ft_strncmp(line, "WE ", 3) == 0);
}

void parse_texture_line(t_game *game, char *line)
{
    char *path;
    if (ft_strncmp(line, "NO ", 3) == 0)
    {
        path = ft_get_value(line + 3);
        game->config.north_texture = path;
    }
    else if (ft_strncmp(line, "SO ", 3) == 0)
    {
        path = ft_strdup(line + 3);
        game->config.south_texture = path;
    }
    else if (ft_strncmp(line, "EA ", 3) == 0)
    {
        path = ft_strdup(line + 3);
        game->config.east_texture = path;
    }
    else if (ft_strncmp(line, "WE ", 3) == 0)
    {
        path = ft_strdup(line + 3);
        game->config.west_texture = path;
    }
    else
        ft_exit(EXIT_FAILURE);
}
int is_color_line(char *line)
{
    return (ft_strncmp(line, "F ", 2) == 0 ||
            ft_strncmp(line, "C ", 2) == 0);
}
void parse_color_line(t_game *game, char *line)
{
    char **colors;
    int r, g, b;
    if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
    {
        colors = ft_split(line + 2, ',');
        if (!colors || !colors[0] || !colors[1] || !colors[2] || ft_strlen(colors) != 3)
            ft_exit(EXIT_FAILURE);
        r = ft_atoi(colors[0]);
        g = ft_atoi(colors[1]);
        b = ft_atoi(colors[2]);
        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
            ft_exit(EXIT_FAILURE);
        if (ft_strncmp(line, "F ", 2) == 0)
            game->config.floor_color = (r << 16) | (g << 8) | b;
        else
            game->config.ceiling_color = (r << 16) | (g << 8) | b;
    }
}
void ft_scipe_empty_lines(char **line, int fd)
{
    while (*line && ft_strlen(*line) == 0)
    {
        free(*line);
        *line = get_next_line(fd);
    }
}