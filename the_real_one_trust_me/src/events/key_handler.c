/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:23:05 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/06 18:23:06 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_key(t_keys *keys, int keycode, int state)
{
	if (keycode == KEY_W)
		keys->w = state;
	else if (keycode == KEY_A)
		keys->a = state;
	else if (keycode == KEY_S)
		keys->s = state;
	else if (keycode == KEY_D)
		keys->d = state;
	else if (keycode == KEY_LEFT)
		keys->left = state;
	else if (keycode == KEY_RIGHT)
		keys->right = state;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		cleanup_exit(game);
	set_key(&game->keys, keycode, 1);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	set_key(&game->keys, keycode, 0);
	return (0);
}
