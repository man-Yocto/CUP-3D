/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:56:00 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/05 00:53:57 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_player_char(char c, size_t j, size_t row, t_player_info *p_info)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		(*p_info->count)++;
		p_info->pos[0] = j + 1;
		p_info->pos[1] = row;
		*p_info->dir = c;
	}
}

void	fill_line_content(char *line, char *raw, size_t width,
		t_player_info *p_info, size_t row)
{
	size_t	j;

	line[0] = ' ';
	j = 0;
	while (raw[j] && raw[j] != '\n')
	{
		line[j + 1] = raw[j];
		check_player_char(raw[j], j, row, p_info);
		j++;
	}
	while (j < width)
		line[++j] = ' ';
	line[j + 1] = ' ';
	line[j + 2] = '\0';
}

int	fill_grid_content(char **grid, char **raw_lines, size_t line_count,
		t_player_info *p_info, size_t width)
{
	size_t	i;
	char	*line;

	i = 0;
	while (i < line_count)
	{
		line = malloc(width + 3);
		if (!line)
			return (1);
		fill_line_content(line, raw_lines[i], width, p_info, i + 1);
		grid[i + 1] = line;
		if (!grid[i + 1])
			return (1);
		i++;
	}
	grid[i + 1] = make_empty_line(width);
	if (!grid[i + 1])
		return (1);
	grid[i + 2] = NULL;
	return (0);
}
