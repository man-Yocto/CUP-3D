/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_padding.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 12:00:00 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/12 12:00:00 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**build_padded_map_with_frame(char **raw_map, int rows, int width)
{
	char	**padded;
	int		t_rows;
	int		t_cols;

	t_rows = rows + 2;
	t_cols = width + 2;
	padded = allocate_padded_map(t_rows, t_cols);
	if (!padded)
		return (NULL);
	fill_top_bottom_rows(padded, t_rows, t_cols);
	fill_middle_rows(padded, raw_map, rows, t_cols);
	return (padded);
}

int	is_map_enclosed_with_padding(char **padded_map, int rows, int cols)
{
	char	**visited;
	int		result;

	if (!padded_map || rows <= 0 || cols <= 0)
		return (0);
	visited = allocate_padded_map(rows, cols);
	if (!visited)
		return (0);
	result = iterative_flood_fill(padded_map, rows, cols, visited);
	free_matrix(visited);
	return (result);
}
