/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:57:35 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/28 00:57:36 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	key_press_bonus(int keycode, t_game *game)
{
	if (keycode == KEY_E)
		try_open_door(game);
	key_press(keycode, game);
	return (0);
}
