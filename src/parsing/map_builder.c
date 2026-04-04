/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:56:00 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/05 00:53:57 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*make_empty_line(size_t width)
{
	char	*line;
	size_t	i;

	line = malloc(width + 3);
	if (!line)
		return (NULL);
	i = 0;
	while (i < width + 2)
		line[i++] = ' ';
	line[i] = '\0';
	return (line);
}

static char	*make_content_line(char *raw, size_t width, t_player_info *p_info)
{
	char	*line;

	line = malloc(width + 3);
	if (!line)
		return (NULL);
	fill_line_content(line, raw, width, p_info, 0);
	return (line);
}

static char	**fill_grid(char **grid, char **raw_lines, size_t line_count,
		t_player_info *p_info)
{
	size_t	width;

	width = getm_length(raw_lines);
	if (fill_grid_content(grid, raw_lines, line_count, p_info, width))
	{
		free_matrix(grid);
		return (NULL);
	}
	return (grid);
}

static char	**alloc_grid(size_t line_count)
{
	char	**grid;
	size_t	i;

	grid = malloc(sizeof(char *) * (line_count + 3));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < line_count + 3)
		grid[i++] = NULL;
	return (grid);
}

static int	validate_player_count(int count, char **grid)
{
	if (count != 1)
	{
		print_error("Invalid player count");
		free_matrix(grid);
		return (1);
	}
	return (0);
}

static int	init_padded_grid(char **grid, size_t width)
{
	grid[0] = make_empty_line(width);
	if (!grid[0])
	{
		free_matrix(grid);
		return (1);
	}
	return (0);
}

char	**build_padded_map(char **raw_lines, size_t width, int *p_pos,
		char *p_dir)
{
	char			**grid;
	size_t			line_count;
	t_player_info	p_info;
	int				p_count;

	line_count = 0;
	while (raw_lines && raw_lines[line_count])
		line_count++;
	grid = alloc_grid(line_count);
	if (!grid)
		return (NULL);
	p_count = 0;
	p_info.pos = p_pos;
	p_info.dir = p_dir;
	p_info.count = &p_count;
	if (init_padded_grid(grid, width))
		return (NULL);
	if (!fill_grid(grid, raw_lines, line_count, &p_info))
		return (NULL);
	if (validate_player_count(p_count, grid))
		return (NULL);
	return (grid);
}

