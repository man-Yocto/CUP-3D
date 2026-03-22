/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:53:39 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/22 16:53:40 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void     init_one_tex(t_texture *t)
{
        t->img = NULL;
        t->addr = NULL;
        t->width = 0;
        t->height = 0;
        t->bpp = 0;
        t->line_len = 0;
        t->endian = 0;
}

static void     init_textures_arr(t_game *game)
{
        int     i;

        i = 0;
        while (i < 5)
        {
                init_one_tex(&game->tex[i]);
                i++;
        }
}

void    init_texture_structs(t_game *game)
{
        init_textures_arr(game);
}