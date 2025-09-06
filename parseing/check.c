#include "../cub3D.h"

int is_texture_line(char *line)
{
    return (ft_strncmp(line, "NO ", 3) == 0 ||
            ft_strncmp(line, "SO ", 3) == 0 ||
            ft_strncmp(line, "EA ", 3) == 0 ||
            ft_strncmp(line, "WE ", 3) == 0);
}

char *ft_get_value(char *line)
{
    char *end;
    while (*line && (*line == ' '))
        line++;
    if (*line == '\0')
        ft_exit(EXIT_FAILURE);
    end  = line + ft_strlen(line) - 1;
    while (end > line && (*end == ' '))
        end--;
    end++;

    return (ft_substr(line, 0, end - line));
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
        path = ft_get_value(line + 3);
        game->config.south_texture = path;
    }
    else if (ft_strncmp(line, "EA ", 3) == 0)
    {
        path = ft_get_value(line + 3);
        game->config.east_texture = path;
    }
    else if (ft_strncmp(line, "WE ", 3) == 0)
    {
        path = ft_get_value(line + 3);
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
    // int i = 0;
    if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
    {        
        colors = ft_split(line + 2, ',');
        if (!colors || !colors[0] || !colors[1] || !colors[2] || colors[3] != NULL)
            ft_error("Invalid color format\n");
        r = ft_atoi(colors[0]);
        g = ft_atoi(colors[1]);
        b = ft_atoi(colors[2]);
        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
            ft_error("Color values must be between 0 and 255\n");
        if (ft_strncmp(line, "F ", 2) == 0)
            game->config.floor_color = (r << 16) | (g << 8) | b;
        else
            game->config.ceiling_color = (r << 16) | (g << 8) | b;
    }
    else
        ft_error("Invalid color line\n");
}
int is_space_only(char *line)
{
    int i = 0;
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\n')
            return (0);
        i++;
    }
    return (1);
}
void ft_scipe_empty_spaces_line(char **line, int fd)
{
    while (*line &&  is_space_only(*line))
        *line = get_next_line(fd);
}