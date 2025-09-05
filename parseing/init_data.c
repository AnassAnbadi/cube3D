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
    ft_scipe_empty_spaces_line(&line, fd);
    while (line) {
        if (is_texture_line(line)) {
            parse_texture_line(game, line);
        } else if (is_color_line(line)) {
            parse_color_line(game, line);
        } else {
            break;
        }
        ft_scipe_empty_spaces_line(&line, fd);
    }
    if (line)
        ft_scipe_empty_lines(&line, fd);
    else
        ft_error("No map data found\n");
    init_mock_map(line, fd);
    
}

int is_empty_or_all_space(char *line) {
    while (*line) {
        if (*line != ' ' && *line != '\n')
            return (0);
        line++;
    }
    return (1);
}

void init_data_map(t_mock_map *head, t_game game) {
    t_mock_map *current;
    int map_length;
    int i;

    map_length = 0;
    current = head;
    while (current) {
        map_length++;
        current = current->next;
    }
    game.map = ft_malloc(sizeof(char *) * (map_length + 1));
    game.map[map_length] = NULL;
    current = head;
    i = map_length - 1;
    while (current) {
        game.map[i] = current->line;
        current = current->next;
        i--;
    }
    check_map(game.map);
    check_player(game.map);
}
void check_map(char **map) {
    int i;
    int j;
    int len;

    len = 0;
    while (map[len])
        len++;
    for (i = 0; i < len; i++) {
        j = 0;
        while (map[i][j]) {
            if (!ft_isin(map[i][j], " 01NSEW")) {
                ft_error("Invalid character in map\n");
            }
            if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W') {
                if (i == 0 || i == len - 1 || j == 0 || j == (int)ft_strlen(map[i]) - 1) {
                    ft_error("Map is not closed\n");
                }
                if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' ||
                    map[i][j - 1] == ' ' || map[i][j + 1] == ' ') {
                    ft_error("Map is not closed\n");
                }
            }
            j++;
        }
    }
}
void init_mock_map(t_game game, char *line, int fd) {
    t_mock_map *head;
    t_mock_map *current;

    head = NULL;
    while (line) {
        if(!is_empty_or_all_space(line))
            ft_error("Map is not closed\n");
        current = ft_malloc(sizeof(t_mock_map));
        current->line = line;
        current->next = head;
        head = current;
        line = get_next_line(fd);
    }
    init_data_map(head, game);
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