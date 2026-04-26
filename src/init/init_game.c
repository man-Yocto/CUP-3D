/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:23:42 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/06 18:34:31 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_colors(t_game *game)
{
	int	*f;
	int	*c;

	f = game->config.floor_rgb;
	c = game->config.ceiling_rgb;
	game->floor_color = (f[0] << 16) | (f[1] << 8) | f[2];
	game->ceil_color = (c[0] << 16) | (c[1] << 8) | c[2];
}

static void	transfer_config(t_game *game, t_config *src)
{
	game->config = *src;
	src->no_path = NULL;
	src->so_path = NULL;
	src->we_path = NULL;
	src->ea_path = NULL;
	src->raw_map_lines = NULL;
	src->map = NULL;
	src->map_data.grid = NULL;
}

int	init_game(t_game *game, t_config *config)
{
	init_game_structs(game);
	transfer_config(game, config);
	set_colors(game);
	if (init_player(game))
		return (cleanup_game(game, NULL));
	if (init_mlx(game))
		return (cleanup_game(game, NULL));
	if (init_textures(game))
		return (cleanup_game(game, NULL));
	return (0);
}

void	init_game_structs(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->floor_color = 0;
	game->ceil_color = 0;
	init_player_st(&game->player);
	init_keys_st(&game->keys);
	init_img_st(&game->img);
	init_textures_arr(game);
	init_config(&game->config);
}
