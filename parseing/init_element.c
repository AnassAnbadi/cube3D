/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:46:19 by aanbadi           #+#    #+#             */
/*   Updated: 2025/09/19 22:54:15 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void ft_init_player(t_data *data)
{
    int i = 0;
    int j = 0;
    int player_count = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (ft_isin(data->map[i][j], "NSEW"))
            {
                player_count++;
                data->player.x = j + 0.5;
                data->player.y = i + 0.5;
                data->p_dir.y = -(data->map[i][j] == 'N') +(data->map[i][j] == 'S');
                data->p_dir.x = (data->map[i][j] == 'E') - (data->map[i][j] == 'W');
                data->plane.y = 0.66 * ((data->map[i][j] == 'E') - (data->map[i][j] == 'W'));
                data->plane.x = -0.66 * ((data->map[i][j] == 'N') + (data->map[i][j] == 'S'));
                data->map[i][j] = '0';
            }
            j++;
        }
        i++;
    }
    if (player_count == 0 || player_count > 1)
        ft_error("No player found or multiple players found in the map\n");
}

void ft_replace_spaces_in_map(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;

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

void check_map(char **map)
{
    int i;
    int j;
    int len;

    len = 0;
    i = 0;
while (map[len])
    len++;
while (i < len) {
    j = 0;
    while (map[i][j]) {
        if (!ft_isin(map[i][j], ft_strjoin(W_S, "01NSEW")))
            ft_error("Invalid character in map\n");
        if (ft_isin(map[i][j], "0NSEW"))
        {
            if (i == 0 || i == len - 1 || j == 0 || j == (int)ft_strlen(map[i]) - 1)
                ft_error("Map is not closed (border)\n");
            if (j >= (int)ft_strlen(map[i - 1]) || j >= (int)ft_strlen(map[i + 1]) ||
                map[i - 1][j] == ' ' || map[i + 1][j] == ' ' ||
                map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
            {
                ft_error("Map is not closed (adjacent to void)\n");
            }
        }
        j++;
    }
    i++;
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
