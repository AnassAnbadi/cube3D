/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:44:55 by aanbadi           #+#    #+#             */
/*   Updated: 2025/09/19 21:44:56 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int ft_white_space(char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int is_space_only(char *line)
{
    int i = 0;
    while (line[i]!= '\0' && line[i] != '\n')
    {
        if (ft_white_space(line[i]) == 0)
            return (0);
        i++;
    }
    if ((i == (int)ft_strlen(line) - 1 && line[0] != '\n') || (i == (int)ft_strlen(line)))
        return (1);
    return (0);
}
char *ft_scipe_empty_spaces_line(char *line, int fd)
{
    while (line && is_space_only(line))
    {
        line = get_next_line(fd);
    }
    return line;
}
char *ft_scipe_spaces(char *line)
{
    while (*line && ft_white_space(*line))
        line++;
    return line;
}