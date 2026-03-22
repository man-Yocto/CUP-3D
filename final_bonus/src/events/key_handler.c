/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:55:26 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/22 16:55:26 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void     set_key(t_keys *keys, int keycode, int state)
{
        if (keycode == KEY_W)
                keys->w = state;
        else if (keycode == KEY_A)
                keys->a = state;
        else if (keycode == KEY_S)
                keys->s = state;
        else if (keycode == KEY_D)
                keys->d = state;
        else if (keycode == KEY_E)
                keys->e = state;
        else if (keycode == KEY_LEFT)
                keys->left = state;
        else if (keycode == KEY_RIGHT)
                keys->right = state;
}

int     key_press(int keycode, t_game *game)
{
        if (keycode == KEY_ESC)
                cleanup_exit(game);
        set_key(&game->keys, keycode, 1);
        return (0);
}

int     key_release(int keycode, t_game *game)
{
        set_key(&game->keys, keycode, 0);
        return (0);
}

int     mouse_press(int button, int x, int y, t_game *game)
{
        (void)x;
        (void)y;

        if (button == MOUSE_LEFT_BUTTON)
        {
                if (!game->mouse_locked)
                {
                        game->mouse_locked = 1;
                        mlx_mouse_hide(game->mlx, game->win);
                        mlx_mouse_move(game->mlx, game->win, WIN_W / 2, WIN_H / 2);
                }
        }
        else if (button == MOUSE_RIGHT_BUTTON)
        {
                if (game->mouse_locked)
                {
                        game->mouse_locked = 0;
                        mlx_mouse_show(game->mlx, game->win);
                }
        }
        return (0);
}