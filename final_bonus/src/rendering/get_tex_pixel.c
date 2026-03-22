/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:41:22 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/22 16:41:22 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    put_pixel(t_img *img, int x, int y, int color)
{
        char *dst;

        dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
        *(unsigned int *)dst = (unsigned int)color;
}

int     get_tex_pixel(t_texture *tex, int x, int y)
{
        char *src;

        src = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
        return (*(unsigned int *)src);
}