/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:23:02 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/06 18:23:03 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	key_press_bonus(int keycode, t_game *game)
{
	if (keycode == KEY_E)
		try_open_door(game);
	if (keycode == KEY_ESC)
	{
		cleanup_door_tex(game);
		cleanup_coins(game);
	}
	key_press(keycode, game);
	return (0);
}
