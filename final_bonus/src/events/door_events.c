/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:54:41 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/22 16:54:42 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     find_door_index(int x, int y, t_door *doors, int door_count)
{
        int     i;

        i = 0;
        while (i < door_count)
        {
                if (doors[i].x == x && doors[i].y == y)
                        return (i);
                i++;
        }
        return (-1);
}

int     hit_door(char **map, t_ray *ray, t_config *config, t_game *game)
{
        int     x;
        int     y;
        int     door_idx;

        x = ray->map_x;
        y = ray->map_y;
        if (!config || !config->doors)
                return (0);
        if (map[y][x] == 'D')
        {
                if (ray->x == WIN_W / 2)
                {
                        door_idx = find_door_index(x, y, config->doors, config->door_count);
                        if (door_idx >= 0)
                                game->target_door = &config->doors[door_idx];
                }
                return (!is_door_open(x, y, config->doors, config->door_count));
        }
        return (0);
}

int     is_door_open(int x, int y, t_door *doors, int door_count)
{
        int     i;

        i = 0;
        while (i < door_count)
        {
                if (doors[i].x == x && doors[i].y == y)
                        return (doors[i].is_open);
                i++;
        }
        return (0);
}