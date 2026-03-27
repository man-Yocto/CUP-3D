/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:55:54 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/28 01:01:35 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_pos(char **map, int x, int y)
{
	size_t	line_len;

	if (y < 0 || map[y] == NULL)
		return (0);
	line_len = ft_strlen(map[y]);
	if (x < 0 || x >= (int)line_len)
		return (0);
	return (1);
}

int	flood_fill(char **map, int x, int y)
{
	if (!is_valid_pos(map, x, y))
		return (1);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	map[y][x] = 'V';
	if (flood_fill(map, x + 1, y))
		return (1);
	if (flood_fill(map, x - 1, y))
		return (1);
	if (flood_fill(map, x, y + 1))
		return (1);
	if (flood_fill(map, x, y - 1))
		return (1);
	return (0);
}

int	check_map_validity(char **map, int x, int y)
{
	if (flood_fill(map, x, y))
	{
		print_error("Map is not enclosed by walls");
		return (0);
	}
	return (1);
}
