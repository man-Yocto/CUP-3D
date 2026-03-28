/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:57:11 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/28 00:57:12 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	create_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "cub3D");
	if (!game->win)
	{
		print_error("Window creation failed");
		return (1);
	}
	return (0);
}

static int	create_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	if (!game->img.img)
	{
		print_error("Image creation failed");
		return (1);
	}
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.line_len, &game->img.endian);
	return (0);
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		print_error("MLX init failed");
		return (1);
	}
	if (create_window(game))
		return (1);
	if (create_image(game))
		return (1);
	return (0);
}
