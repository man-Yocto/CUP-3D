/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 01:11:25 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/28 01:18:28 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_tex_index(t_ray *ray)
{
	if (ray->side == 1 && ray->step_y > 0)
		return (TEX_NO);
	if (ray->side == 1 && ray->step_y < 0)
		return (TEX_SO);
	if (ray->side == 0 && ray->step_x > 0)
		return (TEX_WE);
	return (TEX_EA);
}

double	get_wall_x(t_ray *ray, t_player *p)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = p->y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = p->x + ray->perp_wall_dist * ray->ray_dir_x;
	return (wall_x - floor(wall_x));
}

int	get_tex_x(t_ray *ray, t_texture *tex, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)tex->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

void	init_wall(t_wall *wall, t_ray *ray, t_texture *tex)
{
	wall->step = (double)tex->height / (double)ray->line_height;
	wall->tex_pos = (ray->draw_start - WIN_H / 2 + ray->line_height / 2)
		* wall->step;
}

void	draw_column(t_game *game, t_ray *ray, t_wall *wall, int x)
{
	t_texture	*tex;
	int			tex_y;
	int			y;
	int			color;

	tex = &game->tex[wall->tex_idx];
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)wall->tex_pos % tex->height;
		wall->tex_pos += wall->step;
		color = get_tex_pixel(tex, wall->tex_x, tex_y);
		put_pixel(&game->img, x, y, color);
		y++;
	}
}
