/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:56:35 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/28 01:01:35 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	hit_wall(char **map, int x, int y)
{
	size_t	line_len;

	if (y < 0 || map[y] == NULL)
		return (1);
	line_len = ft_strlen(map[y]);
	if (x < 0 || x >= (int)line_len)
		return (1);
	return (map[y][x] == '1');
}

void	perform_dda(t_ray *ray, char **map)
{
	while (!hit_wall(map, ray->map_x, ray->map_y))
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
}
