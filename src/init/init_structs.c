/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 01:09:25 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/28 01:14:26 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_st(t_player *p)
{
	p->x = 0.0;
	p->y = 0.0;
	p->dir_x = 0.0;
	p->dir_y = 0.0;
	p->plane_x = 0.0;
	p->plane_y = 0.0;
}

static void	init_img_st(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
}

static void	init_keys_st(t_keys *k)
{
	k->w = 0;
	k->a = 0;
	k->s = 0;
	k->d = 0;
	k->left = 0;
	k->right = 0;
}

void	init_structures(t_game *game)
{
	int	i;

	init_player_st(&game->player);
	init_keys_st(&game->keys);
	init_img_st(&game->img);
	i = 0;
	while (i < 4)
	{
		game->tex[i].img = NULL;
		game->tex[i].addr = NULL;
		game->tex[i].width = 0;
		game->tex[i].height = 0;
		game->tex[i].bpp = 0;
		game->tex[i].line_len = 0;
		game->tex[i].endian = 0;
		i++;
	}
}
