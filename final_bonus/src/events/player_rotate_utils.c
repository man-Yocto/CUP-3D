/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:56:11 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/22 16:56:12 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void     rotate_player(t_player *p, double angle)
{
        double  old_dir_x;
        double  old_plane_x;

        old_dir_x = p->dir_x;
        p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
        p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
        old_plane_x = p->plane_x;
        p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
        p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

static void     get_mouse_delta(t_game *game, int *delta_x, int center_x)
{
        int     mouse_x;
        int     mouse_y;

        mlx_mouse_get_pos(game->mlx, game->win, &mouse_x, &mouse_y);
        *delta_x = mouse_x - center_x;
}

void    perform_player_rotation(t_player *p, double angle)
{
        rotate_player(p, angle);
}

void    get_mouse_rotation(t_game *game, int *delta_x, int center_x)
{
        get_mouse_delta(game, delta_x, center_x);
}