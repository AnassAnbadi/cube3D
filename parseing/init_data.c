/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:46:23 by aanbadi           #+#    #+#             */
/*   Updated: 2025/09/19 21:46:23 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_param(t_data *data, char *line, int fd)
{
	line = ft_scipe_empty_spaces_line(line, fd);
	while (line)
	{
		if (is_texture_line(ft_scipe_spaces(line)))
			parse_texture_line(data, ft_scipe_spaces(line));
		else if (is_color_line(ft_scipe_spaces(line)))
		{
			check_color_format(line);
			parse_color_line(data, ft_scipe_spaces(line));
		}
		else
			break ;
		line = get_next_line(fd);
		line = ft_scipe_empty_spaces_line(line, fd);
	}
	if (!line)
		ft_error("No map data found\n");
	line = ft_scipe_empty_spaces_line(line, fd);
	if (ft_sum(get_value(), 6) != 6)
		ft_error("Missing or duplicate configuration parameters\n");
	init_mock_map(data, line, fd);
}

int	is_empty_or_all_space(char *line)
{
	while (*line)
	{
		if (!ft_white_space(*line))
			return (0);
		line++;
	}
	return (1);
}

void	init_data_map(t_mock_map *head, t_data *data)
{
	t_mock_map	*current;
	int			map_length;
	int			i;

	map_length = 0;
	current = head;
	while (current)
	{
		map_length++;
		current = current->next;
	}
	data->map = ft_malloc(sizeof(char *) * (map_length + 1));
	data->map[map_length] = NULL;
	current = head;
	i = map_length - 1;
	while (current)
	{
		data->map[i] = current->line;
		current = current->next;
		i--;
	}
	check_map(data->map);
}

void	init_mock_map(t_data *data, char *line, int fd)
{
	t_mock_map	*head;
	t_mock_map	*current;

	head = NULL;
	while (line)
	{
		if (is_space_only(line))
		{
			if (check_lines_empty(line, fd))
				break ;
			ft_error("Map is not closed2\n");
		}
		current = ft_malloc(sizeof(t_mock_map));
		current->line = ft_get_value(line, 0);
		current->next = head;
		head = current;
		line = get_next_line(fd);
	}
	init_data_map(head, data);
}

void	init_data(t_data *data, char *filename)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("open faild (maybe invalid path or somthing else)\n");
	get_fd_state()[FD] = fd;
	get_fd_state()[STATE] = 2;
	line = get_next_line(fd);
	if (!line)
		ft_error("Empty file\n");
	line = ft_scipe_empty_spaces_line(line, fd);
	init_param(data, line, fd);
	ft_replace_spaces_in_map(data->map);
	ft_init_player(data);
	ft_close_fd();
}
