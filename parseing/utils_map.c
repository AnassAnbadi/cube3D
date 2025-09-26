/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:39:58 by mbenchah          #+#    #+#             */
/*   Updated: 2025/09/26 18:07:52 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_check_map_surrounded(char **map, int i, int j, int len)
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
			if (ft_white_space(map[i][j]))
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	*get_fd_state(void)
{
	static int	fd_state[2];

	return (fd_state);
}

void	ft_close_fd(void)
{
	int	*fd_state;

	fd_state = get_fd_state();
	if (fd_state[STATE] == 2)
		close(fd_state[FD]);
	fd_state[STATE] = 1;
}
