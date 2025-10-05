/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:45:23 by aanbadi           #+#    #+#             */
/*   Updated: 2025/09/19 21:45:23 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static char	*read_from_file(int fd, char *temp_buffer, char *stored_data)
{
	int		bytes_read;
	char	*new_data;

	while (1)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			return (stored_data);
		temp_buffer[bytes_read] = '\0';
		new_data = ft_strjoin(stored_data, temp_buffer);
		if (!new_data)
			return (NULL);
		stored_data = new_data;
		if (ft_strchr(stored_data, '\n'))
			break ;
	}
	return (stored_data);
}

static char	*extract_line(char *stored_data)
{
	char	*line;
	int		line_length;

	if (!stored_data)
		return (NULL);
	line_length = 0;
	while (stored_data[line_length] && stored_data[line_length] != '\n')
		line_length++;
	line = ft_substr(stored_data, 0, line_length + 1);
	return (line);
}

static char	*update_stored_data(char *stored_data)
{
	char	*new_data;
	int		line_length;

	if (!stored_data)
		return (NULL);
	line_length = 0;
	while (stored_data[line_length] && stored_data[line_length] != '\n')
		line_length++;
	if (stored_data[line_length] == '\n')
		line_length++;
	new_data = ft_strdup(&stored_data[line_length]);
	if (new_data && new_data[0] == '\0')
		return (NULL);
	return (new_data);
}

char	*get_next_line(int fd)
{
	static char	*stored_data;
	char		*line;
	char		*temp_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp_buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	stored_data = read_from_file(fd, temp_buffer, stored_data);
	free(temp_buffer);
	line = extract_line(stored_data);
	stored_data = update_stored_data(stored_data);
	return (line);
}
