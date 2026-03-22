/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:23:21 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/22 16:40:23 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     get_tex_x(t_ray *ray, t_texture *tex, double wall_x)
{
        int     tex_x;

        tex_x = (int)(wall_x * (double)tex->width);
        if (ray->side == 0 && ray->ray_dir_x > 0)
                tex_x = tex->width - tex_x - 1;
        if (ray->side == 1 && ray->ray_dir_y < 0)
                tex_x = tex->width - tex_x - 1;
        return (tex_x);
}

void    init_wall(t_wall *wall, t_ray *ray, t_texture *tex)
{
        wall->step = (double)tex->height / (double)ray->line_height;
        wall->tex_pos = (ray->draw_start - WIN_H / 2 + ray->line_height / 2)
                * wall->step;
}