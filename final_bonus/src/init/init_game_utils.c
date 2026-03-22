/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:51:52 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/22 16:51:52 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_game_structs(t_game *game)
{
        game->mlx = NULL;
        game->win = NULL;
        game->floor_color = 0;
        game->ceil_color = 0;
        game->mouse_locked = 0;
        game->target_door = NULL;
        init_core_structs(game);
        init_texture_structs(game);
        init_config(&game->config);
}

void    init_mouse(t_game *game)
{
        game->mouse.last_x = WIN_W / 2;
        game->mouse.last_y = WIN_H / 2;
        mlx_mouse_move(game->mlx, game->win, WIN_W / 2, WIN_H / 2);
}