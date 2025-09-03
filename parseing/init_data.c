#include "../cub3D.h"


void scipe_spaces_line(char **line) {
    char *start = *line;
    while (*start && (*start == ' '))
        start++;
    if (start != *line) {
        free(*line);
        *line = ft_strdup(start);
    }
}

void init_param(t_game *game, char *line, int fd) {
    static int i;
    game->config.north_texture = NULL;
    game->config.south_texture = NULL;
    game->config.east_texture = NULL;
    game->config.west_texture = NULL;
    game->config.floor_color = -1;
    game->config.ceiling_color = -1; 
    while (line) {
        if (is_texture_line(line)) {
            parse_texture_line(game, line);
        } else if (is_color_line(line)) {
            parse_color_line(game, line);
        } else {
            break;
        }
        free(line);
        line = get_next_line(fd);
    }
    if (line)
        ft_scipe_empty_lines(&line, fd);
    init_map(game);
    
}

void init_map(t_game *game) {
    
}
init_data(t_game *game, char *filename) {

char *line;
int fd;

fd = open(filename, O_RDONLY);
if (fd < 0)
    ft_exit(EXIT_FAILURE);
line = get_next_line(fd);
ft_scipe_empty_lines(&line, fd);
init_param(game, line, fd);

{
    
}

}