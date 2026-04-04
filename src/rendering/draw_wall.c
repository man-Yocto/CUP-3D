/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 01:11:25 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/28 01:18:28 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	t_wall		wall;
	t_texture	*tex;
	double		wall_x;

	wall.tex_idx = get_tex_index(ray);
	tex = &game->tex[wall.tex_idx];
	wall_x = get_wall_x(ray, &game->player);
	wall.tex_x = get_tex_x(ray, tex, wall_x);
	init_wall(&wall, ray, tex);
	draw_column(game, ray, &wall, x);
}
