/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:46:19 by aanbadi           #+#    #+#             */
/*   Updated: 2025/09/19 23:50:38 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_init_unit_p(t_data *data, int i, int j)
{
	data->player.x = j + 0.5;
	data->player.y = i + 0.5;
	data->p_dir.y = -(data->map[i][j] == 'N')
		+ (data->map[i][j] == 'S');
	data->p_dir.x = (data->map[i][j] == 'E')
		- (data->map[i][j] == 'W');
	data->plane.y = 0.66 * ((data->map[i][j] == 'E')
			- (data->map[i][j] == 'W'));
	data->plane.x = -0.66 * ((data->map[i][j] == 'N')
			+ (data->map[i][j] == 'S'));
}

void	ft_init_player(t_data *data)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_isin(data->map[i][j], "NSEW"))
			{
				player_count++;
				ft_init_unit_p(data, i, j);
				data->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (player_count == 0 || player_count > 1)
		ft_error("No player found or multiple players found in the map\n");
}

void	ft_replace_spaces_in_map(char **map)
{
	int	i;
	int	j;

	i = 0;
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

void	ft_check_map_surrounded(char **map, int i, int j, int len)
{
	if (i == 0 || i == len - 1 || j == 0
		|| j == (int)ft_strlen(map[i]) - 1)
		ft_error("Map is not closed (border)\n");
	if (j >= (int)ft_strlen(map[i - 1])
		|| j >= (int)ft_strlen(map[i + 1])
		|| map[i - 1][j] == ' ' || map[i + 1][j] == ' '
		|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		ft_error("Map is not closed (adjacent to void)\n");
}

void	check_map(char **map)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (map[len])
		len++;
	while (i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_isin(map[i][j], ft_strjoin(W_S, "01NSEW")))
				ft_error("Invalid character in map\n");
			if (ft_isin(map[i][j], "0NSEW"))
				ft_check_map_surrounded(map, i, j, len);
			j++;
		}
		i++;
	}
}

int	check_lines_empty(char *line, int fd)
{
	while (line)
	{
		if (!is_space_only(line))
			return (0);
		line = get_next_line(fd);
	}
	return (1);
}

void	parse_color_line(t_data *data, char *line)
{
	char	**colors;
	int		rgb[3];

	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
	{
		if (ft_strncmp(line, "F ", 2) == 0)
			get_value()[4]++;
		else
			get_value()[5]++;
		line[ft_strlen(line) - 1] = '\0';
		colors = ft_split(line + 2, ',');
		if (!colors || !colors[0] || !colors[1] || !colors[2] || colors[3])
			ft_error("Invalid color format\n");
		rgb[0] = ft_atoi(colors[0]);
		rgb[1] = ft_atoi(colors[1]);
		rgb[2] = ft_atoi(colors[2]);
		if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0
			|| rgb[1] > 255 || rgb[2] < 0 || rgb[2] > 255)
			ft_error("Color values must be between 0 and 255\n");
		if (ft_strncmp(line, "F ", 2) == 0)
			data->config.floor_color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
		else
			data->config.ceiling_color = (rgb[0] << 16)
				| (rgb[1] << 8) | rgb[2];
	}
}
