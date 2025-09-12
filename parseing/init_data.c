#include "../cub3D.h"


void init_param(t_data *data, char *line, int fd)
{
    line = ft_scipe_empty_spaces_line(line, fd);
    while (line) {
        if (is_texture_line(ft_scipe_spaces(line))) {
            printf("how many time\n");
            parse_texture_line(data, ft_scipe_spaces(line));
        } else if (is_color_line(ft_scipe_spaces(line))) {
            parse_color_line(data, ft_scipe_spaces(line));
            printf("color line\n");
        } else {
            break;
        }
        line = get_next_line(fd);
        line = ft_scipe_empty_spaces_line(line, fd);
    }
    if (!line)
        ft_error("No map data found\n");
    line = ft_scipe_empty_spaces_line(line, fd);
    if(ft_sum(get_value(), 6) != 6)
        ft_error("Missing or duplicate configuration parameters\n");
    init_mock_map(data, line, fd);
    
}

int is_empty_or_all_space(char *line) {
    while (*line) {
        if (*line != ' ' && *line != '\n')
            return (0);
        line++;
    }
    return (1);
}

// void check_player(char **map)
// {

// }

void init_data_map(t_mock_map *head, t_data *data) {
    t_mock_map *current;
    int map_length;
    int i;

    map_length = 0;
    current = head;
    while (current) {
        map_length++;
        current = current->next;
    }
    data->map = ft_malloc(sizeof(char *) * (map_length + 1));
    data->map[map_length] = NULL;
    current = head;
    i = map_length - 1;
    while (current) {
        data->map[i] = current->line;
        current = current->next;
        i--;
    }
    printf("map after init data map\n");
    check_map(data->map);
    // check_player(data.map);
}

int	ft_isin(const char c, const char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
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
            if (!ft_isin(map[i][j], " \r01NSEW")) {
                printf("dbdb (----%d-------) in map at i=%d j=%d\n", map[i][j], i, j);
                ft_error("Invalid character in map\n");
            }
            if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W') {
                if (i == 0 || i == len - 1 || j == 0 || j == (int)ft_strlen(map[i]) - 1) {
                    printf("i=%d j=%d len=%d strlen=%lu\n", i, j, len, ft_strlen(map[i]));
                    ft_error("Map is not closed0\n");
                }
                if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' ||
                    map[i][j - 1] == ' ' || map[i][j + 1] == ' ') {
                    ft_error("Map is not closed1\n");
                }
            }
            j++;
        }
    }
}

int check_lines_empty(char *line, int fd)
{
    while (line )
    {
        if (!is_space_only(line))
            return (0);
        line = get_next_line(fd);
    }
    return (1);
}
void init_mock_map(t_data *data, char *line, int fd) {
    t_mock_map *head;
    t_mock_map *current;

    head = NULL;
    while (line) {
        if(is_space_only(line))
        {
            printf("{%s}\n", line);
            if (check_lines_empty(line, fd))
                break;
            ft_error("Map is not closed2\n");
        }
        current = ft_malloc(sizeof(t_mock_map));
        current->line = line;
        current->line[ft_strlen(current->line) - 1] = '\0';
        current->next = head;
        head = current;
        line = get_next_line(fd);
    }
    init_data_map(head, data);
}

void print_map(char **map)
{
    int i =0;
    int j =0;
    while (map[i])
    {
        j=0;
        while (map[i][j])
        {
            printf("%c",map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    
}
void ft_replace_spaces_in_map(char **map)
{
    int i = 0;
    int j = 0;

    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == ' ')
                map[i][j] = '1';
            j++;
        }
        i++;
    }
}
void init_data(t_data *data, char *filename)
{

    char *line=NULL;
    int fd;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
       ft_error("fd\n");
    line = get_next_line(fd);
    if (!line)
        ft_error("Empty file\n");
    line = ft_scipe_empty_spaces_line(line, fd);
    init_param(data, line, fd);
    ft_replace_spaces_in_map(data->map);
    print_map(data->map);
    close(fd);

}