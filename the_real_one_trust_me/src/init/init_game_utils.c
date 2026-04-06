/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:23:40 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/06 18:34:00 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_one_tex(t_texture *t)
{
	t->img = NULL;
	t->addr = NULL;
	t->width = 0;
	t->height = 0;
	t->bpp = 0;
	t->line_len = 0;
	t->endian = 0;
}

void	init_textures_arr(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		init_one_tex(&game->tex[i]);
		i++;
	}
}

void	init_player_st(t_player *p)
{
	p->x = 0.0;
	p->y = 0.0;
	p->dir_x = 0.0;
	p->dir_y = 0.0;
	p->plane_x = 0.0;
	p->plane_y = 0.0;
}

void	init_img_st(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
}

void	init_keys_st(t_keys *k)
{
	k->w = 0;
	k->a = 0;
	k->s = 0;
	k->d = 0;
	k->left = 0;
	k->right = 0;
}
