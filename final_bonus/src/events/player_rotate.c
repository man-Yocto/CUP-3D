/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:56:30 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/22 16:56:30 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    update_rotation(t_game *game)
{
        if (game->keys.left)
                perform_player_rotation(&game->player, -ROT_SPEED);
        if (game->keys.right)
                perform_player_rotation(&game->player, ROT_SPEED);
}

void    update_mouse_rotation(t_game *game)
{
        int delta_x;
        int center_x;
        int center_y;
        double angle;

        if (!game->mouse_locked)
                return ;
        center_x = WIN_W / 2;
        center_y = WIN_H / 2;
        get_mouse_rotation(game, &delta_x, center_x);
        if (delta_x > -2 && delta_x < 2)
        {
                mlx_mouse_move(game->mlx, game->win, center_x, center_y);
                return ;
        }
        angle = delta_x * MOUSE_SENSITIVITY;
        perform_player_rotation(&game->player, angle);
        mlx_mouse_move(game->mlx, game->win, center_x, center_y);
}
void    init_mouse_system(t_game *game)
{
        mlx_mouse_hide(game->mlx, game->win);
        mlx_mouse_move(game->mlx, game->win, WIN_W / 2, WIN_H / 2);
}