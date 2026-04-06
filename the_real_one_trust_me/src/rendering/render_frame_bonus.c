/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:25:59 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/06 18:26:00 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	render_column(t_game *game, int x)
{
	t_ray	ray;

	ft_memset(&ray, 0, sizeof(t_ray));
	init_ray(&ray, &game->player, x);
	compute_ray_step(&ray, &game->player);
	perform_dda_bonus(&ray, game);
	compute_projection(&ray);
	zbuf_access()[x] = ray.perp_wall_dist;
	if (game->config.map[ray.map_y][ray.map_x] == 'D')
		draw_door_wall(game, &ray, x);
	else
		draw_wall(game, &ray, x);
}

static void	render_sprites(t_game *game)
{
	int			i;
	t_coin_mgr	*m;
	t_texture	*tex;

	m = get_coin_mgr();
	tex = get_coin_frame_tex();
	i = 0;
	while (i < m->count)
	{
		if (!m->arr[i].collected)
			render_coin(game, &m->arr[i], tex);
		i++;
	}
}

void	render_frame(t_game *game)
{
	int	x;

	draw_background(game);
	x = 0;
	while (x < WIN_W)
	{
		render_column(game, x);
		x++;
	}
	render_sprites(game);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
