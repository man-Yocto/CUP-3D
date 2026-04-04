/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder_unpadded.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 01:02:00 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/05 00:38:51 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	extract_player_pos(char **grid, int *p_pos, char *p_dir)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'N' || grid[i][j] == 'S' ||
				grid[i][j] == 'E' || grid[i][j] == 'W')
			{
				p_pos[0] = j;
				p_pos[1] = i;
				*p_dir = grid[i][j];
			}
			j++;
		}
		i++;
	}
}

static char	*process_raw_line(char *raw_line)
{
	char	*line;
	size_t	i;

	line = ft_strdup(raw_line);
	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	line[i] = '\0';
	return (line);
}

static int	fill_unpadded_grid(char **grid, char **raw_lines, size_t line_count)
{
	size_t	i;

	i = 0;
	while (i < line_count)
	{
		grid[i] = process_raw_line(raw_lines[i]);
		if (!grid[i])
		{
			free_matrix(grid);
			return (1);
		}
		i++;
	}
	grid[i] = NULL;
	return (0);
}

char	**build_unpadded_map(char **raw_lines, int *p_pos, char *p_dir)
{
	char	**grid;
	size_t	line_count;

	line_count = 0;
	while (raw_lines && raw_lines[line_count])
		line_count++;
	grid = malloc(sizeof(char *) * (line_count + 1));
	if (!grid)
		return (NULL);
	if (fill_unpadded_grid(grid, raw_lines, line_count))
		return (NULL);
	extract_player_pos(grid, p_pos, p_dir);
	return (grid);
}
