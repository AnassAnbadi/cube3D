/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:46:28 by aanbadi           #+#    #+#             */
/*   Updated: 2025/09/19 21:46:28 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_texture_line(char *line)
{
	return (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0);
}

char *ft_get_value(char *line)
{
	char	*end;
	while (*line && (ft_white_space(*line)))
		line++;
	if (*line == '\0')
	{
		ft_error("Invalid texture path\n");
	}
	end  = line + ft_strlen(line) - 1;
	while (end > line && (ft_white_space(*end)))
		end--;
	end++;

	return (ft_substr(line, 0, end - line));
}

int *get_value(void)
{
	static int values[6];
	return values;
}

void parse_texture_line(t_data *data, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		get_value()[0]++;
		data->config.north_texture = ft_get_value(line + 3);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		get_value()[1]++;
		data->config.south_texture = ft_get_value(line + 3);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		get_value()[2]++;
		data->config.east_texture = ft_get_value(line + 3);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		get_value()[3]++;
		data->config.west_texture = ft_get_value(line + 3);
	}
}
int is_color_line(char *line)
{
	return (ft_strncmp(line, "F ", 2) == 0 ||
			ft_strncmp(line, "C ", 2) == 0);
}
void parse_color_line(t_data *data, char *line)
{
	char **colors;
	int rgb[3];

	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
	{
		if (ft_strncmp(line, "F ", 2) == 0)
			get_value()[4]++;
		else
			get_value()[5]++;
		line[ft_strlen(line) - 1] = '\0';
		colors = ft_split(line + 2, ',');
		if (!colors || !colors[0] || !colors[1] || !colors[2] || colors[3] != NULL)
			ft_error("Invalid color format\n");
		rgb[0] = ft_atoi(colors[0]);
		rgb[1] = ft_atoi(colors[1]);
		rgb[2] = ft_atoi(colors[2]);
		if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255 || rgb[2] < 0 || rgb[2] > 255)
			ft_error("Color values must be between 0 and 255\n");
		if (ft_strncmp(line, "F ", 2) == 0)
			data->config.floor_color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
		else
			data->config.ceiling_color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	}
	else
		ft_error("Invalid color line\n");
}
