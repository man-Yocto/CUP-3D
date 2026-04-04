/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:57:05 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/28 01:10:13 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_structs(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->floor_color = 0;
	game->ceil_color = 0;
	init_structures(game);
	init_config(&game->config);
}
